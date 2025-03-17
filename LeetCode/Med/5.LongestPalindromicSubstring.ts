/* 
1. Intuition
- 각 문자를 중심으로 확장하며 가장 긴 팰린드롬 부분 문자열을 찾는다.

2. Approach
 1. 문자열의 각 인덱스를 중심으로 팰린드롬을 확장한다.
 2. 홀수 길이(단일 문자 중심)와 짝수 길이(연속 두 문자 중심)를 각각 검사한다.
 3. 가장 긴 팰린드롬을 갱신하며 반환한다.

3. Complexity
- Time complexity: O(n^2)
- Space complexity: O(1)
*/

function palindrome(startIdx: number, endIdx: number, str: string): string {
  let result = "";
  while (
    startIdx >= 0 &&
    endIdx <= str.length - 1 &&
    str[startIdx] === str[endIdx]
  ) {
    result = str.substring(startIdx, endIdx + 1);
    startIdx--;
    endIdx++;
  }
  return result;
}

function longestPalindrome(s: string): string {
  if (!s || s.length === 0) return "";

  let result = "";

  for (let i = 0; i < s.length; i++) {
    const oddResult = palindrome(i, i, s);
    const evenResult = palindrome(i, i + 1, s);

    // 1번 odd even 길이 차이
    const currentResult =
      oddResult.length >= evenResult.length ? oddResult : evenResult;
    // 2번 result 와 1번 길이 차이
    result = result.length >= currentResult.length ? result : currentResult;
  }

  return result;
}
