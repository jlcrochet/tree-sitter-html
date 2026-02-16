#!/bin/sh
set -eu

usage() {
    cat <<'EOF'
Usage: scripts/benchmark-stat-cases.sh [-n runs] [-i include_regex]

Runs `tree-sitter test --stat all` multiple times for selected corpus cases and
prints average/min/max bytes/ms per case.

Options:
  -n runs           Number of benchmark runs (default: 20)
  -i include_regex  Regex passed to `tree-sitter test --include`
EOF
}

runs=20
include_regex='character reference - named entity \(common\)|character reference - lt and gt|character reference - quot and apos|character reference - nbsp|edge case - malformed implied end lookahead at EOF \(p/div\)|edge case - malformed implied end lookahead at EOF \(li/li\)'

while getopts "n:i:h" opt; do
    case "$opt" in
        n) runs="$OPTARG" ;;
        i) include_regex="$OPTARG" ;;
        h)
            usage
            exit 0
            ;;
        *)
            usage
            exit 2
            ;;
    esac
done

case "$runs" in
    ''|*[!0-9]*)
        echo "error: runs must be a positive integer" >&2
        exit 2
        ;;
    0)
        echo "error: runs must be greater than 0" >&2
        exit 2
        ;;
esac

tmp_file="${TMPDIR:-/tmp}/tree_sitter_html_stat_cases.$$"
trap 'rm -f "$tmp_file"' EXIT INT TERM

run=1
while [ "$run" -le "$runs" ]; do
    tree-sitter test --stat all --include "$include_regex" \
        | awk '
            /✓/ && /\([0-9.]+ bytes\/ms\)/ {
                line = $0
                sub(/^.*✓[[:space:]]*/, "", line)

                name = line
                sub(/[[:space:]]*\([0-9.]+ bytes\/ms\).*$/, "", name)

                speed = line
                sub(/^.*\(/, "", speed)
                sub(/[[:space:]]*bytes\/ms\).*$/, "", speed)

                printf "%s\t%s\n", name, speed
            }
        ' >> "$tmp_file"
    run=$((run + 1))
done

{
    printf "Benchmark runs: %s\n" "$runs"
    printf "Case\tAvg(bytes/ms)\tMin\tMax\tSamples\n"
    awk -F '\t' '
        {
            name = $1
            speed = $2 + 0
            sum[name] += speed
            count[name]++
            if (!(name in min) || speed < min[name]) min[name] = speed
            if (!(name in max) || speed > max[name]) max[name] = speed
        }
        END {
            for (name in count) {
                printf "%s\t%.3f\t%.3f\t%.3f\t%d\n", name, sum[name] / count[name], min[name], max[name], count[name]
            }
        }
    ' "$tmp_file" | sort -t "$(printf '\t')" -k2,2n
}
