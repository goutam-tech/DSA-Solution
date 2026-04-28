namespace Easy;

public class Solution {
    public int MaxDistance(int[] colors) {
        int n = colors.Length;
        int maxDist = 0;

        for(int i = 0; i < n; i++){
            if(colors[i] != colors[n - 1]){
                maxDist = Math.Max(maxDist, n - 1 -i);
                break;
            }
        }

        for(int i = n - 1; i > 0; i--){
            if(colors[i] != colors[0]){
                maxDist = Math.Max(maxDist, i);
                break;
            }
        }

        return maxDist;
    }
}