#!/usr/bin/env bash
for ns in Html Mathml Svg; do
  lower="${ns,,}"

  ./src/vendor/triehash/triehash.pl \
    --enum-name="${ns}Element" \
    --function-name="lookup_${lower}_element" \
    --label-prefix="${ns}Element_" \
    --counter-name="${ns}Element_Count" \
    "src/tables/${lower}_elements.txt" > "src/tables/${lower}_elements.h"
done

for type in Full Short; do
  lower="${type,,}"

  ./src/vendor/triehash/triehash.pl \
    --enum-name="${type}CharacterReference" \
    --function-name="lookup_${lower}_character_reference" \
    --label-prefix="${type}CharacterReference_" \
    src/tables/"${lower}_character_references.txt" > "src/tables/${lower}_character_references.h"
done
