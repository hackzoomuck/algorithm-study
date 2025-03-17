# Intuition
<!-- Describe your first thoughts on how to solve this problem. -->

# Approach
<!-- Describe your approach to solving the problem. -->

# Complexity
- Time complexity:
<!-- Add your time complexity here, e.g. $$O(n)$$ -->

- Space complexity:
<!-- Add your space complexity here, e.g. $$O(n)$$ -->

# Code
```typescript []
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
```
