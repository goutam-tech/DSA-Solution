class Solution
{
public:
    int maxIndexDifference(string &s)
    {
        int n = s.size();
        vector<int> best(n);
        int runningBest[26];
        for (int i = 0; i < 26; i++)
            runningBest[i] = -1;

        for (int i = n - 1; i >= 0; i--)
        {
            int c = s[i] - 'a';
            if (c < 25 && runningBest[c + 1] != -1)
                best[i] = runningBest[c + 1];
            else
                best[i] = i;
            if (best[i] > runningBest[c])
                runningBest[c] = best[i];
        }

        int ans = -1;
        for (int i = 0; i < n; i++)
        {
            if (s[i] == 'a')
                ans = max(ans, best[i] - i);
        }
        return ans;
    }
};