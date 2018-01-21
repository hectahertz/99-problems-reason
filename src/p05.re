/* Reverse a list. (easy) */
let rev = list => {
  let rec aux = (acc, list) =>
    switch list {
    | [] => acc
    | [h, ...t] => aux([h, ...acc], t)
    };
  aux([], list);
};

Js.log(Array.of_list(rev(["a", "b", "c"])));