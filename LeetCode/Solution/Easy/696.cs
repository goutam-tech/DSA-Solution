namespace Easy;

public class Solution {
    public int CountBinarySubstrings(string s) {
        int result = 0;
        int prevGroupCount = 0;
        int currentGroupCount = 1;

        for(int i = 1; i < s.Length; i++){
            if(s[i] == s[i-1]){
                currentGroupCount++;
            }
            else{
                result += Math.Min(prevGroupCount, currentGroupCount);
                prevGroupCount = currentGroupCount;
                currentGroupCount = 1;
            }
        }

        result += Math.Min(prevGroupCount,currentGroupCount);

        return result;
    }
}