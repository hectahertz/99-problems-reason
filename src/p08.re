/* Eliminate consecutive duplicates of list elements. (medium) */
let rec compress = list =>
  switch list {
  | [] => []
  | [x] => [x]
  | [h, th, ...tt] when h === th => compress([h, ...tt])
  | [h, ...t] => [h, ...compress(t)]
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