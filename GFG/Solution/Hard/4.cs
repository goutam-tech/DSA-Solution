class Solution {
    public string minWindow(string s, string p) {
        if(string.IsNullOrEmpty(s) || string.IsNullOrEmpty(p) || s.Length < p.Length)
          return "";
          
        Dictionary<char,int> need = new Dictionary<char,int>();
        foreach(char c in p)
           need[c] = need.GetValueOrDefault(c,0) + 1;
           
        int required = need.Count;
        int formed = 0;
        
        Dictionary<char,int> windows = new Dictionary<char,int>();
        
        int left = 0, right = 0;
        int minLen = int.MaxValue;
        int minStart = 0;
        
        while(right < s.Length){
            char c = s[right];
            windows[c] = windows.GetValueOrDefault(c,0)+1;
            
            if(need.ContainsKey(c) && windows[c] == need[c])
              formed++;
            
            while(left <= right && formed == required){
                int windowLen = right - left + 1;
                if(windowLen < minLen){
                    minLen = windowLen;
                    minStart = left;
                }
                
                char leftChar = s[left];
                windows[leftChar]--;
                if(need.ContainsKey(leftChar) && windows[leftChar] < need[leftChar])
                  formed--;
                  
                left++;
            }
            right++;
        }
        
        return minLen == int.MaxValue ? "" : s.Substring(minStart,minLen);
    }
}