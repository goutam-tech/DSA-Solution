class Solution
{
public:
    int zigZagArrays(int n, int l, int r)
    {
        const long long MOD = 1000000007LL;
        int m = r - l + 1;
        vector<long long> needInc(m + 1, 1), needDec(m + 1, 1);
        for (int i = 2; i <= n; i++)
        {
            vector<long long> newDec(m + 1, 0), newInc(m + 1, 0);
            long long running = 0;
            for (int v = 1; v <= m; v++)
            {
                newDec[v] = running;
                running = (running + needInc[v]) % MOD;
            }
            running = 0;
            for (int v = m; v >= 1; v--)
            {
                newInc[v] = running;
                running = (running + needDec[v]) % MOD;
            }
            needInc = move(newInc);
            needDec = move(newDec);
        }
        long long ans = 0;
        for (int v = 1; v <= m; v++)
        {
            ans = (ans + needInc[v] + needDec[v]) % MOD;
        }
        return (int)ans;
    }
};