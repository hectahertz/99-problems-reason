/* Find out whether a list is a palindrome. (easy) */
let rev = list => {
  let rec aux = (acc, list) =>
    switch list {
    | [] => acc
    | [h, ...t] => aux([h, ...acc], t)
    };
  aux([], list);
};

let isPalindrome = a => a == rev(a);

Js.log(isPalindrome(["x", "a", "m", "a", "x"]));

Js.log(! isPalindrome(["a", "b"]));