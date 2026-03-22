class Solution {
    public int findKRotation(int[] arr) {
        int n = arr.Length;
        int left = 0, right = n - 1;
        
        while (left < right) {
            int mid = left + (right - left) / 2;
            
            if (arr[mid] > arr[right]) {
                left = mid + 1;
            }
            else {
                right = mid;
            }
        }
        
        return left;
    }
}

/* 
1. Complexity Analysis
    a. Time Complexity:
        - Best case: O(log n).
        - Average case: O(log n).
        - Worst case: O(log n).
        - Reason: Binary search reduces the search space by half each iteration.

    b. Space Complexity:
        - Uses only a constant number of variables (n, left, right, mid): O(1).
        - No extra data structures proportional to input size.
        - Auxiliary space: O(1).


2. Constraints & Assumptions
    - The array is a rotation of a strictly increasing sorted array (all elements distinct).
    - Array is rotated to the right k times, and k is what we want to find.
    - The number of rotations k equals the index of the minimum element.
    - Typical constraints:
        - n up to around 10^5 or 10^6 are fine for this O(log n) solution.


3. Edge Cases
    - Array not rotated at all (already sorted):
        - Example: [1, 2, 3, 4, 5] → answer = 0.
    - Fully rotated array (rotation count equal to n, effectively same as 0):
        - Algorithm still returns 0 (index of smallest).
    - Rotation at first position:
        - Example: [5, 1, 2, 3, 4] → answer = 1.
    - Small arrays:
        - n = 1 → return 0.
        - n = 2 → correctly finds index of smaller element.
    - If `arr` is null or length 0, behavior is undefined in this code:
        - In practice, handle as:
            if (arr == null || arr.Length == 0) {  return -1 or throw, as per problem  } 


4. Possible Optimizations / Variants
    - Early sorted check:
        - Before loop, if arr[0] <= arr[n - 1], array is not rotated → return 0 immediately.
    - Inclusive binary search style:
        - Can also be written with `while (left <= right)` and an explicit sorted-subarray check.
    - Generalization:
        - This pattern is reusable for finding the minimum in a rotated sorted array and as a step in
          problems like "search in rotated sorted array".
*/