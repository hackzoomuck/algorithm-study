function solution(A: number[], K: number): number[] {
  const len = A.length;
  const modValue = K % len;
  const sliceLen = len - modValue;

  const prev = A.slice(0, sliceLen);
  const next = A.slice(sliceLen);
  const result = [...next, ...prev];

  return result;
}
