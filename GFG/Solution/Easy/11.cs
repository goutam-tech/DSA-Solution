using System;

public class Solution 
{
    public bool canAttend(int[][] intervals) 
    {
        if (intervals == null || intervals.Length <= 1)
            return true;
        
        Array.Sort(intervals, (a, b) => a[0].CompareTo(b[0]));
        
        for (int i = 1; i < intervals.Length; i++) 
        {
            if (intervals[i][0] < intervals[i - 1][1]) 
            {
                return false;
            }
        }
        
        return true;
    }
}

/* 
1. Complexity Analysis
    a. Time Complexity:
        - 𝑂(𝑛 log 𝑛), where 𝑛 is number of intervals.
        - Array.Sort takes 𝑂(𝑛 log 𝑛); linear scan takes 𝑂(𝑛).
    b. Space Complexity:
        - 𝑂(1) auxiliary space.
        - Sorting is in-place; only uses loop variables.

2. Edge Cases to Consider
    a. null or ≤1 intervals → return true (trivially attendable).
    b. Touching intervals [1,2],[2,3] → true (non-overlapping).
    c. Strictly overlapping [1,3],[2,4] → false.
    d. Identical intervals [1,3],[1,3] → false.
    e. Unsorted input → algorithm handles via sorting.

3. Implementation
    a. Handle base cases: null/≤1 intervals return true.
    b. Sort intervals by start time using Array.Sort with lambda.
    c. Iterate from second interval, check if intervals[i][0] < intervals[i-1][1].
    d. Return false on first overlap detected.
    e. Return true if no overlaps found.
*/