public class Solution {
    public bool palindromePair(string[] arr) {
        var indexMap = new Dictionary<string, List<int>>();
        for (int i = 0; i < arr.Length; i++) {
            if (!indexMap.ContainsKey(arr[i]))
                indexMap[arr[i]] = new List<int>();
            indexMap[arr[i]].Add(i);
        }

        for (int i = 0; i < arr.Length; i++) {
            string s = arr[i];
            string rev = Reverse(s);

            if (indexMap.ContainsKey(rev)) {
                foreach (int idx in indexMap[rev]) {
                    if (idx != i) return true;
                }
            }

            for (int cut = 1; cut < s.Length; cut++) {
                string prefix = s.Substring(0, cut);
                string suffix = s.Substring(cut);

                if (IsPalindrome(prefix)) {
                    string revSuffix = Reverse(suffix);
                    if (indexMap.ContainsKey(revSuffix)) {
                        foreach (int idx in indexMap[revSuffix]) {
                            if (idx != i) return true;
                        }
                    }
                }

                if (IsPalindrome(suffix)) {
                    string revPrefix = Reverse(prefix);
                    if (indexMap.ContainsKey(revPrefix)) {
                        foreach (int idx in indexMap[revPrefix]) {
                            if (idx != i) return true;
                        }
                    }
                }
            }
        }
        return false;
    }

    private bool IsPalindrome(string s) {
        int l = 0, r = s.Length - 1;
        while (l < r)
            if (s[l++] != s[r--]) return false;
        return true;
    }

    private string Reverse(string s) {
        char[] c = s.ToCharArray();
        Array.Reverse(c);
        return new string(c);
    }
}