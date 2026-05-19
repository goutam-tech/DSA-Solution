using System;

public class Solution {
    private int Simulate(int fromCap, int toCap, int target) {
        int from = fromCap;
        int to = 0;
        int steps = 1;

        while (from != target && to != target) {
            int temp = Math.Min(from, toCap - to);
            to += temp;
            from -= temp;
            steps++;

            if (from == target || to == target) break;

            if (from == 0) {
                from = fromCap;
                steps++;
            }

            if (to == toCap) {
                to = 0;
                steps++;
            }
        }
        return steps;
    }

    private int GCD(int a, int b) {
        while (b != 0) { int t = b; b = a % b; a = t; }
        return a;
    }

    public int minSteps(int m, int n, int d) {
        if (d > Math.Max(m, n)) return -1;
        if (d % GCD(m, n) != 0) return -1;

        return Math.Min(Simulate(m, n, d), Simulate(n, m, d));
    }
}