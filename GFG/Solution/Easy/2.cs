<<<<<<< Updated upstream
namespace GFG;
public class Solution
{
    public List<int> findUnion(int[] a, int[] b)
    {
        var set = new HashSet<int>(a);

        foreach (int x in b)
        {
            set.Add(x);
        }

        return new List<int>(set);
    }
}

/* 
1. Complexity Analysis
    a. Time Complexity:
        - Best case: O(n + m).
        - Average case: O(n + m).
        - Worst case: Up to O((n + m)^2) if hashing degrades badly due to many collisions, but this is rare in practice.
        - In competitive programming, this is generally considered O(n + m) time.

    b. Space Complexity:
        - HashSet<int> stores up to all distinct elements from both arrays: O(n + m).
        - List<int> output also stores up to O(n + m) elements.
        - Auxiliary space (extra data structures): O(n + m).


2. Constraints & Assumptions
    Arrays a and b:
        - May be sorted or unsorted.
        - May contain duplicates.
        - May be empty.
    Elements fit in int.
    Typical constraints:
        - n, m up to around 10^5 or 10^6 work well with this approach in terms of time and memory.


3. Edge Cases
    - a empty, b non-empty → returns union of b.
    - a non-empty, b empty → returns union of a.
    - Both empty → returns an empty list.
    - All elements identical in both arrays → returns a list with that single element.
    - To avoid NullReferenceException, optionally normalize null arrays:
        if (a == null) a = Array.Empty<int>();
        if (b == null) b = Array.Empty<int>();
*/
=======
public class Solution {
    public List<int> findUnion(int[] a, int[] b) {
        var set = new HashSet<int>(a);
        
        foreach(int x in b){
            set.Add(x);
        }
        
        return new List<int>(set);
    }
}
>>>>>>> Stashed changes
