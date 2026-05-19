class Solution {
    public int longestKSubstr(string s, int k) {
        // code here
        if(string.IsNullOrEmpty(s) || k == 0 || k > s.Length)
          return -1;
          
        Dictionary<char, int> charCount = new Dictionary<char,int>();
        int left = 0;
        int maxLength = -1;
        
        for(int right = 0; right < s.Length; right++){
            char rightChar = s[right];
            if(charCount.ContainsKey(rightChar))
               charCount[rightChar]++;
            else
               charCount[rightChar] = 1;
            
            while(charCount.Count > k){
                char leftChar = s[left];
                charCount[leftChar]--;
                if(charCount[leftChar] == 0)
                  charCount.Remove(leftChar);
                left++;
            }
            
            if(charCount.Count == k)
              maxLength = Math.Max(maxLength, right - left + 1);
        }
        return maxLength;
    }
}