public class Solution {
    public char[][] RotateTheBox(char[][] boxGrid) {
        int m = boxGrid.Length, n = boxGrid[0].Length;

        for(int i = 0; i < m; i++){
            int empty = n - 1;
            for(int j = n - 1; j >= 0; j--){
                if(boxGrid[i][j] == '*'){
                    empty = j - 1;
                }
                else if(boxGrid[i][j] == '#'){
                    boxGrid[i][j] = '.';
                    boxGrid[i][empty] = '#';
                    empty--;
                }
            }
        }

        char[][] result = new char[n][];
        for(int i = 0; i < n; i++){
            result[i] = new char[m];
            for(int j = 0; j < m; j++){
                result[i][j] = boxGrid[m - 1 - j][i];
            }
        }

        return result;
    }
}