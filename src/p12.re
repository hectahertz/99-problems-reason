/* Decode a run-length encoded list. (medium) */
type node('a) =
  | One('a)
  | Many(int, 'a);

let decode = list => {
  let rec build_sublist = (acc, count, x) =>
    count == 0 ? acc : build_sublist([x, ...acc], count - 1, x);
  let rec aux = (acc, list) =>
    switch list {
    | [] => acc
    | [One(h), ...t] => aux([h, ...acc], t)
    | [Many(count, h), ...t] => aux(build_sublist(acc, count, h), t)
    };
  List.rev(aux([], list));
};

Js.log(
  Array.of_list(
    decode([
      Many(4, "a"),
      One("b"),
      Many(2, "c"),
      Many(2, "a"),
      One("d"),
      Many(4, "e")
    ])
  )
);