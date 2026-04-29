public class Solution {
    public int MinimumDeletions(string s) {
        int bCount = 0;
        int delections = 0;

        foreach(char c in s){
            if(c == 'b'){
                bCount++;
            }
            else{
                delections = Math.Min(delections+1,bCount);
            }
        }

        return delections;
    }
}