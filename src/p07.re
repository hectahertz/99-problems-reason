/* Flatten a nested list structure. (medium) */
type node('a) =
  | One('a)
  | Many(list(node('a)));

let flatten = list => {
  let rec aux = (acc, list) =>
    switch list {
    | [] => acc
    | [One(h), ...t] => aux([h, ...acc], t)
    | [Many(h), ...t] => aux(aux(acc, h), t)
    };
  List.rev(aux([], list));
};

Js.log(
  Array.of_list(
    flatten([One("a"), Many([One("b"), Many([One("c"), One("d")]), One("e")])])
  )
);