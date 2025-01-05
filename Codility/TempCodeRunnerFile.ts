function solution(A: number[]): number {
  let minResult = 1;
  let set = new Set(A);

  while (1) {
    if (set.has(minResult)) {
      minResult++;
      continue;
    }
    break;
  }

  return minResult;
}
