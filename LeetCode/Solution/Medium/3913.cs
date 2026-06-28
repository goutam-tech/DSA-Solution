public class Solution {
    public string SortVowels(string s) {
        var vowels = new HashSet<char>{'a','e','i','o','u'};
        var freq = new Dictionary<char,int>();
        var firstPos = new Dictionary<char,int>();
        
        for (int i = 0; i < s.Length; i++) {
            char c = s[i];
            if (vowels.Contains(c)) {
                if (!freq.ContainsKey(c)) {
                    freq[c] = 0;
                    firstPos[c] = i;
                }
                freq[c]++;
            }
        }
        
        var sortedVowels = freq.Keys
            .OrderByDescending(v => freq[v])
            .ThenBy(v => firstPos[v])
            .ToList();
        
        var expanded = new List<char>();
        foreach (var v in sortedVowels) {
            for (int i = 0; i < freq[v]; i++) expanded.Add(v);
        }
        
        int idx = 0;
        var chars = s.ToCharArray();
        for (int i = 0; i < chars.Length; i++) {
            if (vowels.Contains(chars[i])) {
                chars[i] = expanded[idx++];
            }
        }
        
        return new string(chars);
    }
}