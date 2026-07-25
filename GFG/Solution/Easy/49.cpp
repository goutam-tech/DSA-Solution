class Solution
{
public:
    int maxCharGap(string &s)
    {
        // code here
        int first[26], last[26];
        for (int i = 0; i < 26; i++)
        {
            first[i] = -1;
            last[i] = -1;
        }
        int n = s.size();
        for (int i = 0; i < n; i++)
        {
            int c = s[i] - 'a';
            if (first[c] == -1)
                first[c] = i;
            last[c] = i;
        }
        int ans = -1;
        for (int i = 0; i < 26; i++)
        {
            if (first[i] != -1 && last[i] != first[i])
            {
                ans = max(ans, last[i] - first[i] - 1);
            }
        }

        return ans;
    }
};