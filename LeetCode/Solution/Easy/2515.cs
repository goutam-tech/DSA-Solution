namespace Easy;

public class Solution {
    public int ClosestTarget(string[] words, string target, int startIndex) {
        int n = words.Length;
        int minDistance = int.MaxValue;

        for(int i = 0; i < n; i++){
            if(words[i] == target){
                int forward = (i - startIndex + n) % n;
                int backward = (startIndex - i + n) % n;
                minDistance = Math.Min(minDistance, Math.Min(forward, backward));
            }
        }

        return minDistance == int.MaxValue ? -1 : minDistance;
    }
}