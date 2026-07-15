class Solution
{
public:
    vector<int> par;
    int find(int x)
    {
        while (par[x] != x)
        {
            par[x] = par[par[x]];
            x = par[x];
        }
        return x;
    }

    void unite(int a, int b)
    {
        a = find(a);
        b = find(b);
        if (a != b)
        {
            par[a] = b;
        }
    }

    int minScore(int n, vector<vector<int>> &roads)
    {
        par.resize(n + 1);
        iota(par.begin(), par.end(), 0);
        for (auto &r : roads)
        {
            unite(r[0], r[1]);
        }
        int root = find(1);
        int ans = INT_MAX;
        for (auto &r : roads)
        {
            if (find(r[0]) == root)
                ans = min(ans, r[2]);
        }
        return ans;
    }
};