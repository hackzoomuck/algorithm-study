/*
1. Intuition

2. Approach

3. Complexity
- Time complexity:

- Space complexity:
*/

function reverse(x: number): number {
  let tmp = x < 0 ? x * -1 : x;
  let isNegative = x < 0;

  tmp = Number(tmp.toString().split("").reverse().join(""));
  if (isNegative) {
    return tmp > 2 ** 31 ? 0 : tmp * -1;
  } else {
    return tmp > 2 ** 31 - 1 ? 0 : tmp;
  }
}
