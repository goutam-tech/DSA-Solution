class Solution {
    public string findLargest(int[] arr) {
        string[] strs = arr.Select(n => n.ToString()).ToArray();
        
        Array.Sort(strs,(a,b) => string.Compare(b + a, a + b, StringComparison.Ordinal));
        
        if(strs[0] == "0") return "0";
        
        return string.Join("", strs);
    }
}