// 3 
class Solution {
    public int lengthOfLongestSubstring(String s) {
        HashSet<Character> charSet = new HashSet();
        int result = 0;
        for(int i=0;i<s.length(); i++){
            int j=i;
            while(j<s.length() && !charSet.contains(s.charAt(j))){
                charSet.add(s.charAt(j));
                result = Math.max(result, j-i+1);
                j++;
            }
            charSet.clear();
        }
        return result;
    }
}