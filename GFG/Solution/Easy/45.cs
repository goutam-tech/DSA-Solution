class Solution {
    public List<int> commonElements(int[] a, int[] b, int[] c) {
        // code here
        var result = new List<int>();
        int i = 0, j = 0, k = 0;
        
        while(i < a.Length && j < b.Length && k < c.Length){
            if(a[i] == b[j] && b[j] == c[k]){
                if(result.Count == 0 || result[result.Count - 1] != a[i]){
                    result.Add(a[i]);
                }
                i++;
                j++;
                k++;
            }
            else if(a[i] <= b[j] && a[i] <= c[k]){
                i++;
            }
            else if(b[j] <= a[i] && b[j] <= c[k]){
                j++;
            }
            else{
                k++;
            }
        }
        return result;
    }
}