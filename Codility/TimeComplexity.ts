// FrogJmp
function solution1(X: number, Y: number, D: number): number {
  return Math.ceil((Y-X)/D);
}

// PermMissingElem
function solution2(A: number[]): number {
  const allXOR = Array.from({ length: A.length }, (_, idx) => idx + 2).reduce(
    (acc, el) => acc ^ el,
    1
  );
  return A.reduce((acc, el) => acc ^ el, allXOR);
}

// PermMissingElem 코드 리뷰 : 불필요한 배열 생성
function solution2_1(A: number[]): number {
  const N = A.length + 1;
  let result = 0;

  for (let i = 1; i <= N; i++) {
    result ^= i;
  }

  for (let el of A) {
    result ^= el;
  }

  return result;
}

// TapeEquilibrium : 시간 초과 O(n^2)
function solution3(A: number[]): number {
  let diff = 2000;
  const len = A.length;

  // slice O(n), reduce O(n) 을 for 문 : O(n^2)
  for (let i = 1; i < len; i++) {
    const prev = A.slice(0, i).reduce((acc, el) => acc + el, 0);
    const next = A.slice(i).reduce((acc, el) => acc + el, 0);
    const difference = Math.abs(prev - next);
    if (diff > difference) diff = difference;
  }

  return diff;
}

// TapeEquilibrium 코드 리뷰 : 시간 복잡도 O(n)
function solution(A: number[]): number {
  const totalSum = A.reduce((acc, el) => acc + el, 0);
  let minDiff = Infinity;
  let leftSum = 0;

  for (let i = 0; i < A.length - 1; i++) {
    leftSum += A[i];
    const rightSum = totalSum - leftSum;
    const difference = Math.abs(leftSum - rightSum);
    minDiff = Math.min(minDiff, difference);
  }

  return minDiff;
}
