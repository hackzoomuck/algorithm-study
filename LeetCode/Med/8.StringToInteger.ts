function myAtoi(s: string): number {
  let resultStr = "";
  const numberArr = ["0", "1", "2", "3", "4", "5", "6", "7", "8", "9"];
  let isNegative = false;
  let result = 0;

  s.trim()
    .split("")
    .some((el, idx) => {
      if (idx === 0 && (el === " " || el === "+")) {
      } else if (idx === 0 && el === "-") {
        isNegative = true;
      } else if (numberArr.includes(el)) {
        resultStr += el;
      } else {
        return true;
      }
    });

  result = Number(resultStr);

  if (isNegative) {
    return result > 2 ** 31 ? 2 ** 31 * -1 : result * -1;
  } else {
    return result > 2 ** 31 - 1 ? 2 ** 31 - 1 : result;
  }
}
