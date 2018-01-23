/* Modified run-length encoding. (easy) */
type node('a) =
  | One('a)
  | Many(int, 'a);

let encode = list => {
  let build_elem = (count, elem) => count == 1 ? One(elem) : Many(count, elem);
  let rec aux = (count, acc, list) =>
    switch list {
    | [] => []
    | [x] => [build_elem(count + 1, x), ...acc]
    | [h, ...[th, ..._] as t] when h == th => aux(count + 1, acc, t)
    | [h, ...t] => aux(0, [build_elem(count + 1, h), ...acc], t)
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