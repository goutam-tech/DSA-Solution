class Solution {
    public int findSmallest(int[] arr) {
        // code here
        System.Array.Sort(arr);
        
        int smallest = 1;
        
        foreach(int num in arr){
            if(num > smallest){
                break;
            }
            smallest += num;
        }
        
        return smallest;
    }
}