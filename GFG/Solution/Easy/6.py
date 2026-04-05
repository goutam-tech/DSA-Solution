#User function Template for python3

class Solution:
    @staticmethod
    def findMinDiff(arr,m):
        if m == 0 or not arr:
            return 0
        
        if len(arr) < m:
            return -1
        
        arr.sort()
        
        return min(arr[i + m - 1] - arr[i] for i in range(len(arr) - m + 1))

# 1. Complexity Analysis
#     a. Time Complexity:
#         - 𝑂(𝑛 log 𝑛), where 𝑛 is the length of arr.
#         - Sorting takes 𝑂(𝑛 log 𝑛), sliding window iteration takes 𝑂(𝑛).
#     b. Space Complexity:
#         - 𝑂(log 𝑛) worst case.
#         - Python's Timsort uses 𝑂(log 𝑛) recursion stack; no extra arrays needed.

# 2. Edge Cases to Consider
#     a. m == 0 or empty arr → return 0 (trivial case).
#     b. len(arr) < m → return -1 (impossible to form window).
#     c. m == 1 → minimum difference is always 0.
#     d. All elements equal → returns 0.
#     e. Already sorted input → still works efficiently after sort.

# 3. Implementation
#     a. Check base cases: m==0/empty → 0; len(arr)<m → -1.
#     b. Sort the array in ascending order.
#     c. Iterate over all possible starting indices i from 0 to len(arr)-m.
#     d. For each window arr[i:i+m], compute arr[i+m-1] - arr[i].
#     e. Return the minimum of all such differences.