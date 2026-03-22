class Solution {
    public int missingNum(int[] arr) {
        long n = arr.Length + 1;
        long expNum = n * (n + 1) / 2;
        
        long actualNum = 0;
        foreach (int num in arr) {
            actualNum += num;
        }
        
        return (int)(expNum - actualNum);
    }
}

/* 
1. Complexity Analysis
    a. Time Complexity:
        - Best case: O(n).
        - Average case: O(n).
        - Worst case: O(n).
        - Reason: Single pass to compute the sum of the array (size n), all arithmetic operations are O(1).

    b. Space Complexity:
        - Uses a few scalar variables (n, expNum, actualNum): O(1).
        - No extra data structures proportional to input size.
        - Auxiliary space (extra data structures): O(1).


2. Constraints & Assumptions
    - The array represents a sequence of distinct integers from 1 to N with exactly one number missing.
    - Let the length of the array be n; then N = n + 1.
    - Array elements:
        - Are positive integers in the range [1, N].
        - Are distinct.
    - Typical constraints:
        - n up to around 10^5 or 10^6 work well.
        - Sum formula uses `long` to avoid overflow when computing N * (N + 1) / 2.

3. Edge Cases
    - Missing number is 1 (smallest value).
    - Missing number is N (largest value).
    - Array of length 1 (only one number present, one missing).
    - Large N where `int` sum might overflow:
        - Handled by using `long` for `expNum` and `actualNum`.
    - To avoid NullReferenceException, you could optionally normalize null:
        if (arr == null || arr.Length == 0) {
            // Depends on problem definition: either return 1, -1, or throw an exception.
        }

4. Possible Optimizations / Variants
    - XOR approach:
        - Compute XOR of all numbers from 1 to N and XOR of all array elements, then XOR both results to get the missing number.
        - Same time complexity O(n) and space O(1), but avoids potential overflow without `long`.
*/