class Solution
{
public:
    vector<int> parent, rnk;

    int find(int x)
    {
        while (parent[x] != x)
        {
            parent[x] = parent[parent[x]];
            x = parent[x];
        }
        return x;
    }

    void unite(int a, int b)
    {
        a = find(a);
        b = find(b);
        if (a == b)
            return;
        if (rnk[a] < rnk[b])
            swap(a, b);
        parent[b] = a;
        if (rnk[a] == rnk[b])
            rnk[a]++;
    }

    vector<bool> pathExistenceQueries(int n, vector<int> &nums, int maxDiff, vector<vector<int>> &queries)
    {
        parent.resize(n);
        rnk.assign(n, 0);
        for (int i = 0; i < n; i++)
        {
            parent[i] = i;
        }

        for (int i = 0; i + 1 < n; i++)
        {
            if (nums[i + 1] - nums[i] <= maxDiff)
            {
                unite(i, i + 1);
            }
        }

        vector<bool> ans;
        ans.reserve(queries.size());
        for (auto &q : queries)
        {
            int u = q[0], v = q[1];
            ans.push_back(find(u) == find(v));
        }
        return ans;
    }
};