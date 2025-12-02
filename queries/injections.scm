(element
  (start_tag (tag_name) @name)
  (text) @injection.content
  (#match? @name "[Ss][Cc][Rr][Ii][Pp][Tt]")
  (#set! injection.language "javascript")
)

(element
  (start_tag (tag_name) @name)
  (text) @injection.content
  (#match? @name "[Ss][Tt][Yy][Ll][Ee]")
  (#set! injection.language "css")
)
