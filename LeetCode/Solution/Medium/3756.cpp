class Solution
{
public:
    vector<int> sumAndMultiply(string s, vector<vector<int>> &queries)
    {
        const long long MOD = 1e9 + 7;
        int m = s.size();

        vector<int> P;
        vector<int> D;

        P.reserve(m);
        D.reserve(m);
        for (int i = 0; i < m; i++)
        {
            if (s[i] != '0')
            {
                P.push_back(i);
                D.push_back(s[i] - '0');
            }
        }

        int t = D.size();
        vector<long long> cval(t + 1, 0);
        vector<long long> pow10(t + 1, 1);
        vector<long long> sdig(t + 1, 0);

        for (int i = 1; i <= t; i++)
        {
            cval[i] = (cval[i - 1] * 10 + D[i - 1]) % MOD;
            pow10[i] = (pow10[i - 1] * 10) % MOD;
            sdig[i] = sdig[i - 1] + D[i - 1];
        }

        int q = queries.size();
        vector<int> ans(q);

        for (int i = 0; i < q; i++)
        {
            int l = queries[i][0], r = queries[i][1];

            int a = lower_bound(P.begin(), P.end(), l) - P.begin();

            int b = upper_bound(P.begin(), P.end(), r) - P.begin() - 1;

            if (a > b)
            {
                ans[i] = 0;
                continue;
            }

            int lo = a + 1, hi = b + 1;
            long long len = hi - lo + 1;

            long long x = ((cval[hi] - cval[lo - 1] * pow10[len]) % MOD + MOD) % MOD;
            long long sum = sdig[hi] - sdig[lo - 1];

            long long result = (x * (sum % MOD)) % MOD;
            ans[i] = (int)result;
        }

        return ans;
    }
};