class Solution {
    public double findMedianSortedArrays(int[] nums1, int[] nums2) {
        double sum = 0;
        for(int i=0;i<nums1.length;i++){
            sum += nums1[i];
        }
        for(int i=0;i<nums2.length;i++){
            sum += nums2[i];
        }
        sum /= nums1.length+ nums2.length;
        return sum;  
    }
}

// Wrong Answer : 2058 / 2096 testcases passed
// retry tommorow