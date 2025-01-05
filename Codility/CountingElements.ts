function frogRiverOne(X: number, A: number[]): number {
  const leafPositions = new Set<number>();
  let earliestTime = -1;

  for (let i = 0; i < A.length; i++) {
    leafPositions.add(A[i]);

    if (leafPositions.size === X) {
      earliestTime = i;
      break;
    }
  }

  return earliestTime;
}

function permCheck(A: number[]): number {
  const permutation = new Set(A);
  if (permutation.size === A.length && Math.max(...A) === A.length) {
    return 1;
  }
  return 0;
}

// 문제 내용 : Calculate the values of counters after applying all alternating operations: increase counter by 1; set value of all counters to current maximum.
// 시간 복잡도 : O(M+N)
// 개선 방법 : for 문에서 최대인 경우 배열을 초기화 (조건이 발생할 때마다 배열 전체를 업데이트하지 않고, 지연 적용(Lazy Update) 처리)
function maxCounters(N: number, A: number[]): number[] {
  let result = Array(N).fill(0);
  let maxElement = 0;
  let lastMaxElement = 0;

  A.forEach((el) => {
    if (el === N + 1) {
      lastMaxElement = Math.max(maxElement, lastMaxElement);
    } else {
      const idx = el - 1;
      result[idx] = Math.max(result[idx], lastMaxElement);
      result[idx]++;
      maxElement = Math.max(result[idx], maxElement);
    }
  });

  for (let i = 0; i < N; i++) {
    result[i] = Math.max(result[i], lastMaxElement);
  }

  return result;
}

// function missingInteger1(A: number[]): number {
//   let minResult = 1;
//   let set = new Set(A);

//   while (1) {
//     if (set.has(minResult)) {
//       minResult++;
//       continue;
//     }
//     break;
//   }

//   console.log("min : ", minResult);
//   return minResult;
// }

// 개선 방법 : 무조건 1 ~ A.length+1 의 숫자 중에서 return 되기에 for문으로 변경
// 개선된 부분 : 불필요한 변수 줄이고, for로 제한
function missingInteger2(A: number[]): number {
  let set = new Set(A);

  for (let i = 1; i <= A.length + 1; i++) {
    if (!set.has(i)) {
      return i;
    }
  }

  return 1;
}
