/*
  1. Intuition
  - 문자열을 numRow개의 행에 따라 Zigzag 패턴으로 배치한다.
  - 각 행을 개별 문자열로 관리 후, 최종적으로 합치는 방식으로 접근한다.
  
  2. Approach
  - numRows 크기의 문자열 배열을 생성해 각 행을 저장한다.
  - 문자열 s 순차적으로 순회하며, 현재 위치에 해당하는 행에 문자를 추가한다.
  - location이 첫 번째 행(0) 또는 마지막 행(numRows -1)에 도달하면 방향을 전환하다.
  - 최종적으로 모든 행을 하나의 문자열로 합쳐 반환한다.
  
  3. Complexity
  - Time complexity: O(n) (문자열을 한 번 순회하며 각 문자에 대한 O(1) 연산 수행)
  - Space complexity: O(n) 
*/

function convert(s: string, numRows: number): string {
  if (numRows === 1 || s.length <= numRows) return s; // asIs -> toBe : 변환이 필요 없는 경우 조건문으로 처리하기

  let stringArr: string[] = Array(numRows).fill("");
  let location = 0; // 현재 행 위치 (0 ~ numRow-1)
  let direction = 1; // 이동 방향 (1; 아래, -1: 위)

  for (const char of s) {
    stringArr[location] += char;
    if (location === 0) direction = 1;
    if (location === numRows - 1) direction = -1;
    location += direction;
  };

  return stringArr.join("");
}


// function asIsConvert(s: string, numRows: number): string {
//   let stringArr: string[] = Array(numRows).fill("");
//   let location = 0; // 0 ~ numRow-1
//   let direction = 0; // 1, 0, -1
//   s.split("").forEach((el) => {
//     stringArr[location] += el;
//     if (location === 0 && numRows - 1 > 0) direction = 1;
//     if (location === numRows - 1 && numRows - 1 > 0) direction = -1;
//     location += direction;
//   });

//   return stringArr.join("");
// }
