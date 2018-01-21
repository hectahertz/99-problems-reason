/* Pack consecutive duplicates of list elements into sublists. (medium) */
let pack = list => {
  let rec aux = (curr, acc, list) =>
    switch list {
    | [] => []
    | [h] => [[h, ...curr], ...acc]
    | [h, ...[th, ..._] as t] when h == th => aux([h, ...curr], acc, t)
    | [h, ...t] => aux([], [[h, ...curr], ...acc], t)
    };
  List.rev(aux([], [], list));
};

Js.log(
  Array.of_list(
    pack([
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