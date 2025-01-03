function solution(A: number[]): number {
  const set = new Set();
  A.forEach((el) => {
    if (set.has(el)) {
      set.delete(el);
    } else {
      set.add(el);
    }
  });

  const array = [...set];
  const result = array[0] as number;

  return result;
}

// 다른 방법 : XOR(eXclusive OR) 
// a ^ b ^ b = a 로 쌍을 쉽게 제거하고, 남은 유일한 값을 찾아내는 데 사용 가능
function solution(A: number[]): number {
  return A.reduce((acc, el) => acc ^ el, 0);
}
