class Solution
{
public:
    bool wifiRange(string &s, int x)
    {
        int n = s.size();
        int reach = -1;

        for (int i = 0; i < n; i++)
        {
            if (i > reach)
            {
                bool found = false;
                for (int j = max(0, i - x); j <= min(i + x, n - 1); j++)
                {
                    if (s[j] == '1')
                    {
                        reach = j + x;
                        found = true;
                        break;
                    }
                }
                if (!found)
                    return false;
            }
        }
        return true;
    }
};