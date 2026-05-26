class Solution {
    public bool checkElements(int start, int end, int[] arr) {
        // code here
        HashSet<int> set = new HashSet<int>(arr);
        
        for(int i = start; i <= end; i++){
            if(!set.Contains(i)) return false;
        }
        
        return true;
    }
}