class Solution {
    public int GetSecondLargest(int[] arr) {
        int n = arr.Length;
        if(n < 2) return -1;
        
        Array.Sort(arr);
        
        for(int i = n - 2; i >= 0; i--){
            if(arr[i] < arr[n-1])
              return arr[i];
        }
        
        return -1;
    }
}

/* 
1. Complexity Analysis
    a. Time Complexity:
        - 𝑂(𝑛 log 𝑛), where 𝑛 is the length of arr.
        - Array.Sort takes 𝑂(𝑛 log 𝑛); backward scan takes 𝑂(𝑛).
    b. Space Complexity:
        - 𝑂(log 𝑛) worst case.
        - C# Array.Sort is in-place with 𝑂(log 𝑛) recursion stack; no extra data structures.

2. Edge Cases to Consider
    a. n < 2 → return -1 (insufficient elements).
    b. All elements identical → return -1 (no distinct second largest).
    c. Duplicates of largest → skips them correctly.
    d. Negative numbers → works as comparison is numerical.
    e. Already sorted input → still 𝑂(𝑛 log 𝑛) due to sort.

3. Implementation
    a. Check if n < 2, return -1.
    b. Sort the array in non-decreasing order using Array.Sort.
    c. Start from second last index (n-2) down to 0.
    d. Return first arr[i] < arr[n-1] (largest).
    e. If no such element, return -1.
*/