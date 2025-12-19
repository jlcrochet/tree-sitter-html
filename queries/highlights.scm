(doctype) @comment
(tag_name) @tag
(erroneous_end_tag) @markup.error
(comment) @comment
(attribute_name) @attribute
"=" @operator
(quoted_attribute_value) @string
(unquoted_attribute_value) @string
[
	"'" "\""
] @punctuation
(character_reference) @constant.character.escape
(invalid_character_reference) @markup.error
[
	"<![CDATA[" "]]>"
] @constant.character.escape
