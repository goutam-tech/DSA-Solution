public class Solution {
    public int MinPartitions(string n) {
        int maxDigit = 0;

        foreach (char c in n)
        {
            int digit = c - '0';
            if (digit > maxDigit)
                maxDigit = digit;

            if (maxDigit == 9)
                return 9;
        }
        return maxDigit;
    }
}