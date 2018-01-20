/* Find the last but one (last and penultimate) elements of a list. (easy) */
let rec lastTwo = list =>
  switch list {
  | [] => None
  | [_] => None
  | [x, y] => Some((x, y))
  | [_, ...x] => lastTwo(x)
  };

Js.log(lastTwo(["a", "b", "c", "d"]));

Js.log(lastTwo(["a"]));