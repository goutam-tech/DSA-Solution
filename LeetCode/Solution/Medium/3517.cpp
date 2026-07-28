class Solution
{
public:
    string smallestPalindrome(string s)
    {
        int freq[26] = {0};
        for (char c : s)
            freq[c - 'a']++;
        int n = s.size();
        string half;
        char mid = 0;
        for (int i = 0; i < 26; i++)
        {
            half.append(freq[i] / 2, 'a' + i);
            if (freq[i] % 2)
                mid = 'a' + i;
        }
        string rev = half;
        reverse(rev.begin(), rev.end());
        if (n % 2)
            return half + mid + rev;
        return half + rev;
    }
};