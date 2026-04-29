public class Solution {
    public int MinFlips(string s) {
        int n = s.Length;

        int[] mismatchA = new int[2 * n];
        int[] mismatchB = new int[2 * n];

        for(int i = 0; i < 2 * n; i++){
            char c = s[i % n];
            char expectA = i % 2 == 0 ? '0' : '1';
            char expectB = i % 2 == 0 ? '1' : '0';
            mismatchA[i] = c == expectA ? 0 : 1;
            mismatchB[i] = c == expectB ? 0 : 1;
        }

        int windowA = 0, windowB = 0;
        for(int i = 0; i < n; i++){
            windowA += mismatchA[i];
            windowB += mismatchB[i];
        }

        int minFlips = Math.Min(windowA, windowB);

        for(int i = 1; i < n; i++){
            windowA += mismatchA[i + n - 1] - mismatchA[i - 1];
            windowB += mismatchB[i + n - 1] - mismatchB[i - 1];
            minFlips = Math.Min(minFlips, Math.Min(windowA, windowB));
        }
        return minFlips;
    }
}