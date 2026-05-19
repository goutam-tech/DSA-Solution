public class Solution {
    public void solveSudoku(int[,] mat) {
        int[] rows = new int[9];
        int[] cols = new int[9];
        int[] boxes = new int[9];

        for (int i = 0; i < 9; i++) {
            for (int j = 0; j < 9; j++) {
                int val = mat[i, j];
                if (val != 0) {
                    int bit = 1 << val;
                    rows[i] |= bit;
                    cols[j] |= bit;
                    boxes[(i / 3) * 3 + j / 3] |= bit;
                }
            }
        }

        Solve(mat, rows, cols, boxes, 0);
    }

    private bool Solve(int[,] mat, int[] rows, int[] cols, int[] boxes, int pos) {
        while (pos < 81 && mat[pos / 9, pos % 9] != 0) pos++;
        if (pos == 81) return true;

        int r = pos / 9, c = pos % 9, b = (r / 3) * 3 + c / 3;
        int used = rows[r] | cols[c] | boxes[b];

        for (int num = 1; num <= 9; num++) {
            int bit = 1 << num;
            if ((used & bit) != 0) continue;
            rows[r] |= bit;
            cols[c] |= bit;
            boxes[b] |= bit;
            mat[r, c] = num;
            if (Solve(mat, rows, cols, boxes, pos + 1)) return true;
            rows[r] &= ~bit;
            cols[c] &= ~bit;
            boxes[b] &= ~bit;
            mat[r, c] = 0;
        }

        return false;
    }
}