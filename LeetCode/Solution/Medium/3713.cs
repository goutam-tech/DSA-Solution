public class Solution {
    public int LongestBalanced(string s) {
        int n = s.Length;
        int maxLength = 0;

        for(int i = 0; i < n; i++){
            Dictionary<char,int> freq = new Dictionary<char,int>();

            for(int j = i; j < n; j++){
                char c = s[j];
                if(freq.ContainsKey(c))
                   freq[c]++;
                else
                   freq[c] = 1;

                if(IsBalanced(freq)){
                    maxLength = Math.Max(maxLength, j - i + 1);
                }
            }
        }

        return maxLength;
    }

    private static bool IsBalanced(Dictionary<char,int> freq){
        if(freq.Count == 0)
           return false;

        int firstFreq = freq.Values.First();
        return freq.Values.All(f => f == firstFreq);
    }
}