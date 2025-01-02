function solution(N: number): number {
  const gap = N.toString(2)
    .split("1")
    .filter((el) => el !== "");

  // 1. 기존 코드 (forEach)
  //   let maxGap = 0;
  //   if (gap.length > 1) {
  //     gap.forEach((e) => {
  //       if (maxGap < e.length) {
  //         maxGap = e.length;
  //       }
  //     });
  //   }

  // 2. 수정 코드 (reduce) : 누적값 계산, 상태 공유 안함
  return gap.length > 1
    ? gap.reduce((acc, el) => Math.max(acc, el.length), 0)
    : 0;
}
