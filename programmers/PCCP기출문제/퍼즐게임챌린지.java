class Solution {
    public int solution(int[] diffs, int[] times, long limit) {
        int answer = 0;

        answer = binarySearch(diffs, times, limit);

        return answer;
    }

    public int binarySearch(int[] diffs, int[] times, long limit) {
        int start = 1;
        int end = 100000;
        int mid = 0;
        
        while(start <= end) {   
            mid =  (start + end) / 2;
            boolean pass = getTotalPlayTime(diffs, times, mid) <= limit ? true : false;
            if(pass) {
                end = mid-1;
            } else {
                start = mid+1;
            }
        }
        return start;
    }

    public long getTotalPlayTime(int[] diffs, int[] times, int level) {
        long totalPlayTime = 0;
        for(int idx=0; idx< diffs.length; idx++){
            totalPlayTime += getPlayTime(diffs, times, idx, level);
        }
        return totalPlayTime;
    }

    public long getPlayTime(int[] diffs, int[] times, int idx, int level) {
        if(diffs[idx] <= level) {
            return times[idx];
        } else {
            return idx >= 1 ? (times[idx] + times[idx-1]) * (diffs[idx] - level) + times[idx] :  (times[idx] + 1) * (diffs[idx] - level);
        }
    }
}
