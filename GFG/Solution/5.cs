namespace GFG
{
    class Solution
    {
        public void pushZerosToEnd(int[] arr) {
            int insertPos = 0;
            
            foreach (int num in arr) {
                if (num != 0) {
                    arr[insertPos++] = num;
                }
            }
            
            while (insertPos < arr.Length)
                arr[insertPos++] = 0;
        }
    }
}

/* 
1. Complexity Analysis
    a. Time Complexity:
        - Best case: O(n).
        - Average case: O(n).
        - Worst case: O(n).
        - Reason: One pass to compact non-zero elements and one pass (at most) to fill remaining positions with zeros. Total work is linear in array size. [web:31][web:32]

    b. Space Complexity:
        - Uses only a few scalar variables (insertPos and loop variable): O(1).
        - Operates in-place on the input array, no extra array or collection used.
        - Auxiliary space: O(1). [web:31][web:32]


2. Constraints & Assumptions
    - Input: integer array `arr`.
    - The array:
        - May contain any integers (positive, negative, zero).
        - May contain multiple zeros or no zeros.
        - May be empty.
    - The relative order of all non-zero elements must be preserved (stable). [web:33][web:35][web:36]
    - Typical constraints: n up to around 10^5 or 10^6 are fine for this O(n), O(1) approach. [web:31][web:38]


3. Edge Cases
    - No zeros in the array:
        - Example: [1, 2, 3] → array remains [1, 2, 3].
        - First loop writes all elements in place; second loop does nothing.
    - All elements are zero:
        - Example: [0, 0, 0] → remains [0, 0, 0].
        - First loop never enters `if (num != 0)`, `insertPos` stays 0; second loop writes zeros to all positions.
    - Mixed zeros and non-zeros:
        - Example: [0, 1, 0, 3, 12] → [1, 3, 12, 0, 0].
    - Empty array:
        - `arr.Length == 0` → both loops run zero times, safe.
    - Null array:
        - Current code will throw `NullReferenceException`.
        - Optional handling:
            if (arr == null) {
                // either do nothing, return, or throw a custom exception as per problem definition
            }


4. Possible Optimizations / Variants
    - Swap-based two-pointer variant:
        - Use two indices (slow, fast). When `arr[fast] != 0` and `arr[slow] == 0`, swap them and move both pointers. [web:35][web:39]
        - Same time: O(n), space: O(1), but sometimes fewer writes when there are many zeros.
    - Early exit (micro-optimization):
        - Track whether any zero was seen; if not, skip the fill-zero phase.
    - Reusability:
        - Pattern is a standard two-pointer / compaction technique that can generalize to "move all elements satisfying a predicate to one side" problems. [web:31][web:37]
*/