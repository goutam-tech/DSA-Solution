public class Solution {
    public int LongestCommonPrefix(int[] arr1, int[] arr2) {
        var prefixes = new HashSet<string>();

        foreach(int num in arr1){
            string s = num.ToString();
            for(int i = 1; i <= s.Length; i++){
                prefixes.Add(s.Substring(0, i));
            }
        }

        int maxLen = 0;

        foreach(int num in arr2){
            string s = num.ToString();
            for (int i = 1; i <= s.Length; i++) {
                string prefix = s.Substring(0, i);
                if (prefixes.Contains(prefix)) {
                    maxLen = Math.Max(maxLen, i);
                }
            }
        }

        return maxLen;
    }
}