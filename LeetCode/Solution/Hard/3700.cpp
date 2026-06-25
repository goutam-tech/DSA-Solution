class Solution
{
public:
    static constexpr long long MOD = 1000000007LL;

    using Matrix = std::vector<std::vector<long long>>;

    Matrix multiply(const Matrix &A, const Matrix &B)
    {
        int n = A.size();
        Matrix C(n, std::vector<long long>(n, 0));

        for (int i = 0; i < n; i++)
        {
            for (int k = 0; k < n; k++)
            {
                if (!A[i][k])
                    continue;
                long long aik = A[i][k];
                for (int j = 0; j < n; j++)
                {
                    if (!B[k][j])
                        continue;
                    C[i][j] = (C[i][j] + aik * B[k][j]) % MOD;
                }
            }
        }
        return C;
    }

    Matrix power(Matrix base, long long exp)
    {
        int n = base.size();
        Matrix res(n, std::vector<long long>(n, 0));
        for (int i = 0; i < n; i++)
            res[i][i] = 1;

        while (exp)
        {
            if (exp & 1)
                res = multiply(res, base);
            base = multiply(base, base);
            exp >>= 1;
        }
        return res;
    }

    int zigZagArrays(int n, int l, int r)
    {
        long long m = r - l + 1;

        if (n == 1)
            return m % MOD;
        if (m == 1)
            return 0;

        int sz = 2 * (int)m;

        std::vector<long long> init(sz, 0);

        for (int v = 0; v < m; v++)
        {
            init[v] = v;
            init[m + v] = m - 1 - v;
        }

        if (n == 2)
        {
            long long ans = 0;
            for (long long x : init)
                ans = (ans + x) % MOD;
            return (int)ans;
        }

        Matrix T(sz, std::vector<long long>(sz, 0));

        for (int v = 0; v < m; v++)
        {
            for (int u = 0; u < v; u++)
            {
                T[v][m + u] = 1;
            }
        }

        for (int v = 0; v < m; v++)
        {
            for (int u = v + 1; u < m; u++)
            {
                T[m + v][u] = 1;
            }
        }

        Matrix P = power(T, n - 2);

        std::vector<long long> finalState(sz, 0);

        for (int i = 0; i < sz; i++)
        {
            long long cur = 0;
            for (int j = 0; j < sz; j++)
            {
                cur = (cur + P[i][j] * init[j]) % MOD;
            }
            finalState[i] = cur;
        }

        long long ans = 0;
        for (long long x : finalState)
            ans = (ans + x) % MOD;

        return (int)ans;
    }
};