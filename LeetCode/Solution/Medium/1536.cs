public class Solution {
    public int MinSwaps(int[][] grid) {
        int n = grid.Length;

        int[] lastone = new int[n];
        for(int i = 0; i < n; i++){
            lastone[i] = -1;
            for(int j = n - 1; j >= 0; j--){
                if(grid[i][j] == 1){
                    lastone[i] = j;
                    break; 
                }
            }
        }

        int totalSwaps = 0;
        for(int i = 0; i < n; i++){
            if(lastone[i] <= i) continue;

            int j = i  + 1;
            while(j < n && lastone[j] > i) j++;

            if(j == n) return -1;

            while(j > i){
                int temp = lastone[j];
                lastone[j] = lastone[j - 1];
                lastone[j - 1] = temp;
                j--;
                totalSwaps++;
            }
        }

        return totalSwaps;
    }
}