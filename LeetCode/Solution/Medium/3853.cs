public class Solution {
    public string MergeCharacters(string s, int k) {
        var result = new StringBuilder(s.Length);

        int[] cnt = new int[26];
        for (int t = 0; t < s.Length; t++) {
            char c = s[t];
            int idx = c - 'a';
            if (cnt[idx] > 0)
                continue;

            result.Append(c);
            cnt[idx]++;

            if (result.Length > k) {
                char drop = result[result.Length - k - 1];
                cnt[drop - 'a']--;
            }
        }

        return result.ToString();
    }
}