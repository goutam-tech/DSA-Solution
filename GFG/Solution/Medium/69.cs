class Solution {
    public bool isProduct(int[] arr, long target) {
        // code here
        var seen = new HashSet<long>();
        foreach(var num in arr){
            if(num != 0 && target % num == 0 && seen.Contains(target / num))
                return true;
            seen.Add(num);
        }
        
        return false;
    }
}