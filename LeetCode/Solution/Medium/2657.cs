public class Solution {
    public int[] FindThePrefixCommonArray(int[] A, int[] B) {
        int n = A.Length;
        int[] C = new int[n];
        bool[] seen = new bool[n + 1];
        int common = 0;

        for(int i = 0; i < n; i++){
            if(seen[A[i]]) common++;
            else seen[A[i]] = true;

            if(seen[B[i]]) common++;
            else seen[B[i]] = true;

            C[i] = common;
        }

        return C;
    }
}