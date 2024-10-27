package Hard;

import java.util.ArrayList;
import java.util.Arrays;
import java.util.Collections;
import java.util.List;
import java.util.stream.IntStream;

// Arrays.sort(n) 시간 복잡도 : 평균 O(nlogn) / 최악 O(n^2)
// Collections.sort(n) 시간 복잡도 : 평균 O(nlogn) / 최악 O(nlogn)
// IntStream.concat(Instream A, Instream B).toArray() 로 2개의 int 배열을 1개의 배열로 합침
class MedianOfTwoSortedArrays {
    public double findMedianSortedArrays(int[] nums1, int[] nums2) {
        double sum = 0;
        // 1
        int[] totalArrays = IntStream.concat(Arrays.stream(nums1), Arrays.stream(nums2)).toArray();
        Arrays.sort(totalArrays);

        // 2  Time Complexity: O((M+N)Log(M+N)), Space Complexity : O(M+N)
        // List<Integer> list = new ArrayList<>();
        
        // for(int num : nums1) {
        //     list.add(num);
        // }
        // for(int num : nums2) {
        //     list.add(num);
        // }
        // Collections.sort(list);
        // int[] totalArrays = list.stream().mapToInt(Integer::intValue).toArray();
        
        int arrayLen = totalArrays.length;
        if(arrayLen%2 == 0) {
            sum = (totalArrays[arrayLen/2-1] + totalArrays[arrayLen/2]);
            sum /= 2;
        } else {
            sum = totalArrays[arrayLen/2];
        }

        return sum;
    }
}