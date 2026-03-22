class Solution {
    public int[] findClosestPair(int[] arr1, int[] arr2, int x) {
        int n = arr1.Length;
        int m = arr2.Length;
        
        int left = n - 1;
        int right = 0;
        
        int closestDiff = int.MaxValue;
        int[] result = new int[2];
        
        while(left >= 0 && right < m){
            int currentSum = arr1[left] + arr2[right];
            int diff = Math.Abs(currentSum - x);
            
            if(diff < closestDiff){
                closestDiff = diff;
                result[0] = arr1[left];
                result[1] = arr2[right];
            }
            
            if(currentSum  < x){
                right++;
            }
            else if(currentSum > x){
                left--;
            }
            else{
                break;
            }
        }
        
        return result;
    }
}

/* 
1. Complexity Analysis
    a. Time Complexity:
        - 𝑂(𝑛 + 𝑚), where 𝑛 and 𝑚 are lengths of arr1 and arr2.
        - Single two-pointer traversal visits each element at most once.
    b. Space Complexity:
        - 𝑂(1) auxiliary space.
        - Only uses few variables and result array; modifies no input.

2. Edge Cases to Consider
    a. Empty arrays → handles gracefully (returns some pair).
    b. Exact match (sum == x) → breaks early, returns exact pair.
    c. One array much smaller → still works efficiently.
    d. All sums overshoot x → returns closest from left end.
    e. Arrays not sorted → algorithm assumes sorted inputs.

3. Implementation
    a. Initialize left = n-1 (largest in arr1), right = 0 (smallest in arr2).
    b. While pointers valid, compute currentSum = arr1[left] + arr2[right].
    c. Track closest difference and update result if better.
    d. If currentSum < x, increment right (need larger sum).
    e. If currentSum > x, decrement left (need smaller sum).
    f. Return closest pair found.
*/