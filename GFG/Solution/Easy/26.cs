class Solution {
    public List<int> Intersection(int[] a, int[] b) {
        List<int> result = new List<int>();
        int i = 0, j = 0;
        
        while (i < a.Length && j < b.Length) {
            if (a[i] < b[j]) {
                i++;
            } else if (a[i] > b[j]) {
                j++;
            } else {
                if (result.Count == 0 || result[result.Count - 1] != a[i]) {
                    result.Add(a[i]);
                }
                i++;
                j++;
            }
        }
        
        return result;
    }
}