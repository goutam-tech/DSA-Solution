class Solution {
    public int smallestSubstring(string s) {
        // code here
        int[] count = new int[3];
        int left = 0, formed = 0, minLen = int.MaxValue;
        
        for(int right = 0; right < s.Length; right++){
            int c = s[right] - '0';
            if(count[c] == 0) formed++;
            count[c]++;
            
            while(formed == 3){
                minLen = Math.Min(minLen, right - left + 1);
                int l = s[left] - '0';
                count[l]--;
                if(count[l] == 0) formed--;
                left++;
            }
        }
        
        return minLen == int.MaxValue ? -1 : minLen;
    }
}