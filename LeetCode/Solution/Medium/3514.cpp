class Solution
{
public:
    int uniqueXorTriplets(vector<int> &nums)
    {
        constexpr int MAXV = 2048;
        bitset<MAXV> present, pairXor, ans;
        for (int x : nums)
            present[x] = 1;

        vector<int> U;
        for (int v = 0; v < MAXV; v++)
            if (present[v])
                U.push_back(v);

        for (int u : U)
            for (int v : U)
                pairXor[u ^ v] = 1;

        for (int w : U)
            for (int p = 0; p < MAXV; p++)
                if (pairXor[p])
                    ans[p ^ w] = 1;

        return (int)ans.count();
    }
};