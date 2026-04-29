using System;

public class Solution {
    public int MinOperations(string s) {
        int n = s.Length;

        int sortedSuffixStart = n - 1;
        while (sortedSuffixStart > 0 && s[sortedSuffixStart - 1] <= s[sortedSuffixStart]) {
            sortedSuffixStart--;
        }

        if (sortedSuffixStart == 0) return 0;

        int sortedPrefixEnd = 0;
        while (sortedPrefixEnd < n - 1 && s[sortedPrefixEnd] <= s[sortedPrefixEnd + 1]) {
            sortedPrefixEnd++;
        }

        char currentMax = s[0];
        for (int i = 0; i < n - 1; i++) {
            if (s[i] > currentMax) currentMax = s[i];
            if (currentMax <= s[i + 1] && i + 1 >= sortedSuffixStart) {
                return 1;
            }
        }

        char currentMin = s[n - 1];
        for (int i = n - 1; i > 0; i--) {
            if (s[i] < currentMin) currentMin = s[i];
            if (s[i - 1] <= currentMin && i - 1 <= sortedPrefixEnd) {
                return 1;
            }
        }

        char maxRight = s[1];
        for (int i = 2; i < n; i++) {
            if (s[i] > maxRight) maxRight = s[i];
        }
        if (s[0] <= maxRight) return 2;

        char minLeft = s[0];
        for (int i = 1; i < n - 1; i++) {
            if (s[i] < minLeft) minLeft = s[i];
        }
        if (minLeft <= s[n - 1]) return 2;

        if (n == 2) return -1;
        return 3;
    }
}