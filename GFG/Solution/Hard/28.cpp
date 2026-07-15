class Solution
{
public:
    int countSubstring(string &s)
    {
        // Code Here
        int n = s.size();
        vector<int> bit(2 * n + 3, 0);
        auto upd = [&](int i)
        {
            for (; i <= 2 * n + 2; i += i & (-i))
            {
                bit[i]++;
            }
        };
        auto qry = [&](int i) -> int
        {
            int r = 0;
            for (; i > 0; i -= i & (-i))
            {
                r += bit[i];
            }
            return r;
        };
        int prefix = 0;
        int ans = 0;
        upd(prefix + n + 1);
        for (int j = 0; j < n; j++)
        {
            prefix += (s[j] == '1') ? 1 : -1;
            int idx = prefix + n + 1;
            ans += qry(idx - 1);
            upd(idx);
        }
        return ans;
    }
};