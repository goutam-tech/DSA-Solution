class Solution {
    public string largestSwap(string s) {
        char[] chars = s.ToCharArray();
        int n = chars.Length;

        for (int i = 0; i < n - 1; i++)
        {
            char maxChar = chars[i];
            for (int j = i + 1; j < n; j++)
                if (chars[j] > maxChar) maxChar = chars[j];

            if (maxChar <= chars[i]) continue;
            for (int j = n - 1; j > i; j--)
            {
                if (chars[j] == maxChar)
                {
                    (chars[i], chars[j]) = (chars[j], chars[i]);
                    return new string(chars);
                }
            }
        }
        return s;
    }
}

/* 
1. Complexity Analysis
    a. Time Complexity:
        - 𝑂(𝑛²), where 𝑛 is the string length.
        - Outer loop runs 𝑂(𝑛), inner max-finding loop 𝑂(𝑛), swap search 𝑂(𝑛).
    b. Space Complexity:
        - 𝑂(𝑛) for char array conversion.
        - Constant additional variables.

2. Edge Cases to Consider
    a. Single character → return original (no swap possible).
    b. Already lexicographically largest → return original.
    c. All identical characters → return original.
    d. Swap needed at multiple positions → takes first improvement.
    e. Largest character appears multiple times → swaps rightmost occurrence.

3. Implementation
    a. Convert string to mutable char array.
    b. For each position i from 0 to n-2:
       - Find maximum character in suffix arr[i..n-1].
       - If suffix max > arr[i], find rightmost occurrence of maxChar.
       - Swap arr[i] with that position and return immediately.
    c. If no beneficial swap found, return original string.
*/