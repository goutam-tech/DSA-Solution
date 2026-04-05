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