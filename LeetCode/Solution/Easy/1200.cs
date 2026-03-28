public class Solution {
    public IList<IList<int>> MinimumAbsDifference(int[] arr) {
        Array.Sort(arr);
        
        int n = arr.Length;
        IList<IList<int>> res = new List<IList<int>>();
        int minDiff = int.MaxValue; 
        for (int i = 0; i < n - 1; i++) { 
            int diff = arr[i + 1] - arr[i]; 
            if (diff < minDiff) { 
                minDiff = diff; 
            } 
        }
        for(int i=0;i<n - 1;i++){
            int diff = arr[i + 1] - arr[i]; 
            if (diff == minDiff) { 
                res.Add(new List<int> { arr[i], arr[i + 1] }); 
            }
        }
        return res;
    }
}