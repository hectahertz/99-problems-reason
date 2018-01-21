/* Eliminate consecutive duplicates of list elements. (medium) */
let rec compress = list =>
  switch list {
  | [] => []
  | [x] => [x]
  | [h, ...[th, ...tt] as t] =>
    h === th ? compress([h, ...tt]) : [h, ...compress(t)]
  };

Js.log(
  Array.of_list(
    compress([
      "a",
      "a",
      "a",
      "a",
      "b",
      "c",
      "c",
      "a",
      "a",
      "d",
      "e",
      "e",
      "e",
      "e"
    ])
  )
);