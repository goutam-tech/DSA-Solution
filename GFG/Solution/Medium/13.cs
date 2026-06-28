class Solution {
    public int longestSubstr(string s, int k) {
        // code here
        int[] freq = new int[26];
        int left = 0, maxFreq = 0, result = 0;
        
        for(int right = 0; right < s.Length; right++){
            freq[s[right] - 'A']++;
            maxFreq = Math.Max(maxFreq, freq[s[right] - 'A']);
            
            while ((right - left + 1) - maxFreq > k) {
                freq[s[left] - 'A']--;
                left++;
            }
            
            result = Math.Max(result, right - left + 1);
        }
        
        return result;
    }
}