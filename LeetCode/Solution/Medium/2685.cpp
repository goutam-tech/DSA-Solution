class Solution
{
public:
    vector<int> par, sz;

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
        if (a == b)
            return;
        if (sz[a] < sz[b])
            swap(a, b);
        par[b] = a;
        sz[a] += sz[b];
    }

    int countCompleteComponents(int n, vector<vector<int>> &edges)
    {
        par.resize(n);
        sz.assign(n, 1);
        iota(par.begin(), par.end(), 0);
        vector<int> edgeCount(n, 0);
        for (auto &e : edges)
        {
            int a = find(e[0]), b = find(e[1]);
            if (a == b)
            {
                edgeCount[a]++;
            }
            else
            {
                if (sz[a] < sz[b])
                    swap(a, b);
                par[b] = a;
                sz[a] += sz[b];
                edgeCount[a] += edgeCount[b] + 1;
            }
        }
        int ans = 0;
        for (int i = 0; i < n; i++)
        {
            if (find(i) == i)
            {
                long long k = sz[i];
                if (edgeCount[i] == k * (k - 1) / 2)
                    ans++;
            }
        }
        return ans;
    }
};