function passingCars(A: number[]): number {
  let rightCar = 0;
  let result = 0;
  A.forEach((el) => {
    if (el === 0) {
      rightCar++;
    } else {
      result += rightCar;
    }
  });

  return result > 1000000000 ? -1 : result;
}

function CountDiv(A: number, B: number, K: number): number {
  const startDiv = Math.ceil(A / K);
  const lastDiv = Math.floor(B / K);
  return lastDiv - startDiv + 1;
}

function GenomicRangeQuery(S: string, P: number[], Q: number[]): number[] {
  // A, C, G, T : 1, 2, 3, 4
  const dna = {
    A: new Array(S.length + 1).fill(0),
    C: new Array(S.length + 1).fill(0),
    G: new Array(S.length + 1).fill(0),
    T: new Array(S.length + 1).fill(0),
  };

  let result: number[] = new Array();

  for (let i = 0; i < S.length + 1; i++) {
    dna.A[i + 1] = dna.A[i] + (S[i] === "A" ? 1 : 0);
    dna.C[i + 1] = dna.C[i] + (S[i] === "C" ? 1 : 0);
    dna.G[i + 1] = dna.G[i] + (S[i] === "G" ? 1 : 0);
    dna.T[i + 1] = dna.T[i] + (S[i] === "T" ? 1 : 0);
  }

  for (let i = 0; i < P.length; i++) {
    const end = Q[i] + 1;
    const start = P[i];
    if (dna.A[end] - dna.A[start] > 0) {
      result.push(1);
      continue;
    } else if (dna.C[end] - dna.C[start] > 0) {
      result.push(2);
      continue;
    } else if (dna.G[end] - dna.G[start] > 0) {
      result.push(3);
      continue;
    } else {
      result.push(4);
      continue;
    }
  }

  return result;
}

// 평균을 내는 값이 적을 수록 더 큰 영향을 주기에 2, 3개로 제한하여 시작 인덱스를 구함. 시간복잡도 O(n)
// 모든 값을 비교할 시에는 시간복잡도 O(n^2) 
function MinAvgTwoSlice(A: number[]): number {
  const n = A.length;
  let minIdx = 0;
  let minAverage = Infinity;

  for (let i = 0; i < n - 1; i++) {
    if ((A[i] + A[i + 1]) / 2 < minAverage) {
      minAverage = (A[i] + A[i + 1]) / 2;
      minIdx = i;
    }

    if (i < n - 2) {
      if ((A[i] + A[i + 1] + A[i + 2]) / 3 < minAverage) {
        minAverage = (A[i] + A[i + 1] + A[i + 2]) / 3;
        minIdx = i;
      }
    }
  }

  return minIdx;
}
