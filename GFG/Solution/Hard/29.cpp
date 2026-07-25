class Solution
{
public:
    static const int MOD = 1000000007;

    long long modPow(long long x, long long y)
    {
        long long res = 1;
        x %= MOD;
        while (y)
        {
            if (y & 1)
                res = (res * x) % MOD;
            x = (x * x) % MOD;
            y >>= 1;
        }
        return res;
    }

    int minOperations(vector<int> &b)
    {
        int n = b.size();
        vector<bool> vis(n, false);
        vector<int> cycles;

        for (int i = 0; i < n; i++)
        {
            if (!vis[i])
            {
                int len = 0;
                int cur = i;
                while (!vis[cur])
                {
                    vis[cur] = true;
                    cur = b[cur] - 1;
                    len++;
                }
                cycles.push_back(len);
            }
        }

        vector<int> spf(n + 1);
        for (int i = 0; i <= n; i++)
            spf[i] = i;
        for (int i = 2; (long long)i * i <= n; i++)
        {
            if (spf[i] == i)
            {
                for (int j = i * i; j <= n; j += i)
                {
                    if (spf[j] == j)
                        spf[j] = i;
                }
            }
        }

        unordered_map<int, int> maxPower;
        for (int length : cycles)
        {
            unordered_map<int, int> freq;
            while (length > 1)
            {
                int p = spf[length];
                int cnt = 0;
                while (length % p == 0)
                {
                    length /= p;
                    cnt++;
                }
                freq[p] = cnt;
            }
            for (auto &[p, cnt] : freq)
            {
                maxPower[p] = max(maxPower[p], cnt);
            }
        }

        long long ans = 1;
        for (auto &[p, cnt] : maxPower)
        {
            ans = (ans * modPow(p, cnt)) % MOD;
        }
        return (int)ans;
    }
};