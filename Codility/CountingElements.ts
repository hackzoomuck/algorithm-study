// FrogRiverOne
function solution(X: number, A: number[]): number {
  const leafPositions = new Set<number>();
  let earliestTime = -1;

  for (let i = 0; i < A.length; i++) {
    set.add(A[i]);

    if (set.size === X) {
      earliestTime = i;
      break;
    }
  }

  return earliestTime;
}

// PermCheck
function solution(A: number[]): number {
  const permutation = new Set(A);
  if (permutation.size === A.length && Math.max(...A) === A.length) {
    return 1;
  }
  return 0;
}

