/* Run-length encoding of a list. (easy) */
let encode = list => {
  let rec aux = (count, acc, list) =>
    switch list {
    | [] => []
    | [x] => [(count + 1, x), ...acc]
    | [h, ...[th, ..._] as t] when h == th => aux(count + 1, acc, t)
    | [h, ...t] => aux(0, [(count + 1, h), ...acc], t)
    };
  List.rev(aux(0, [], list));
};

Js.log(
  Array.of_list(
    encode([
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