class Solution {
    public int kokoEat(int[] arr, int k) {
        int left = 1;
        int right = 0;
        
        foreach(int pile in arr){
            right = Math.Max(right, pile);
        }
        
        int answer = right;
        
        while(left <= right){
            int mid = left + (right - left) / 2;
            
            long hours = 0;
            foreach(int pile in arr){
                hours += (pile + mid -1) / mid;
            }
            
            if(hours <= k){
                answer = mid;
                right = mid-1;
            }
            else{
                left = mid + 1;
            }
        }
        return answer;
    }
}