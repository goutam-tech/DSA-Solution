class Solution {
    public int getLastMoment(int n, int[] left, int[] right) {
        int maxTime = 0;
        
        foreach(int pos in left){
            maxTime = Math.Max(maxTime,pos);
        }
        foreach(int pos in right){
            maxTime = Math.Max(maxTime,n-pos);
        }
        
        return maxTime;
    }
}