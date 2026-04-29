namespace Hard;

public class Solution {
    public string FindTheString(int[][] lcp) {
        int n = lcp.Length;
        char[] word = new char[n];
        Array.Fill(word, '\0');
        
        char next = 'a';
        for (int i = 0; i < n; i++) {
            if (word[i] != '\0') continue;
            if (next > 'z') return "";
            word[i] = next++;
            for (int j = i + 1; j < n; j++) {
                if (lcp[i][j] > 0) word[j] = word[i];
            }
        }
        
        for (int i = 0; i < n; i++) {
            for (int j = 0; j < n; j++) {
                if (i == j) {
                    if (lcp[i][j] != n - i) return "";
                    continue;
                }
                int expected;
                if (word[i] != word[j]) {
                    expected = 0;
                } else {
                    expected = (i + 1 < n && j + 1 < n) ? lcp[i + 1][j + 1] + 1 : 1;
                }
                if (lcp[i][j] != expected) return "";
            }
        }
        
        return new string(word);
    }
}