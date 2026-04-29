public class Solution {
    public double ChampagneTower(int poured, int query_row, int query_glass) {
        double[][] tower = new double[query_row+1][];

        for(int i = 0; i <= query_row; i++){
            tower[i] = new double[i+1];
        }

        tower[0][0] = poured;

        for(int row = 0; row < query_row; row++){
            for(int col = 0; col <= row; col++){
                double overflow = (tower[row][col] - 1.0) / 2.0;

                if(overflow > 0){
                    tower[row + 1][col] += overflow;
                    tower[row + 1][col + 1] += overflow;
                }
            }
        }

        return Math.Min(1.0, tower[query_row][query_glass]);
    }
}