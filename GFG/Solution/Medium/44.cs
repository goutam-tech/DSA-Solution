public class Solution {
    public int totalElements(int[] arr) {
        Dictionary<int,int> count = new Dictionary<int,int>();
        int left = 0, maxLen = 0;
        
        for(int right = 0; right < arr.Length; right++){
            if(!count.ContainsKey(arr[right]))
              count[arr[right]] = 0;
              
            count[arr[right]]++;
            
            while(count.Count > 2){
                count[arr[left]]--;
                if(count[arr[left]] == 0)
                  count.Remove(arr[left]);
                
                left++;
            }
            
            maxLen = Math.Max(maxLen, right - left + 1);
        }
        
        return maxLen;
    }
}