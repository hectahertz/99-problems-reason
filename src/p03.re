/* Find the k'th element of a list. (easy) */
let rec lastTwo = (~list, ~k) =>
  switch list {
  | [] => None
  | [h, ..._] when k == 1 => Some(h)
  | [_, ...t] => lastTwo(~list=t, ~k=k - 1)
  };

Js.log(lastTwo(~list=["a", "b", "c", "d", "e"], ~k=3));

Js.log(lastTwo(~list=["a"], ~k=3));