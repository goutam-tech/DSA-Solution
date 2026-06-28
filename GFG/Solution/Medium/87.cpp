class Solution
{
public:
    string chooseSwap(string &s)
    {
        int n = s.size();
        vector<int> first(26, n);
        for (int i = 0; i < n; i++)
        {
            int c = s[i] - 'a';
            if (first[c] == n)
                first[c] = i;
        }
        for (int i = 0; i < n; i++)
        {
            int y = s[i] - 'a';
            int bestX = -1;
            for (int x = 0; x < y; x++)
            {
                if (first[x] < n && first[x] > i)
                {
                    bestX = x;
                    break;
                }
            }
            if (bestX != -1)
            {
                char c1 = 'a' + bestX, c2 = 'a' + y;
                for (int j = 0; j < n; j++)
                {
                    if (s[j] == c1)
                        s[j] = c2;
                    else if (s[j] == c2)
                        s[j] = c1;
                }
                return s;
            }
        }
        return s;
    }
};