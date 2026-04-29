public class Solution {
    public bool HasAllCodes(string s, int k) {
        int n = 1 << k;
        if(s.Length - k + 1 < n) return false;

        var seen = new HashSet<string>();

        for(int i =  0; i <= s.Length - k; i++){
            seen.Add(s.Substring(i,k));

            if(seen.Count == n) return true; 
        }

        return false;
    }
}