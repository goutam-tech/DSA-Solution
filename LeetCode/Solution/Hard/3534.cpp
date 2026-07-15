class Solution
{
public:
    vector<int> pathExistenceQueries(int n, vector<int> &nums, int maxDiff, vector<vector<int>> &queries)
    {
        vector<int> idx(n);
        iota(idx.begin(), idx.end(), 0);
        sort(idx.begin(), idx.end(), [&](int a, int b)
             { return nums[a] < nums[b]; });

        vector<int> sortedNums(n), pos(n);
        for (int i = 0; i < n; i++)
        {
            sortedNums[i] = nums[idx[i]];
            pos[idx[i]] = i;
        }

        int LOG = 1;
        while ((1 << LOG) < n)
            LOG++;
        LOG++;

        vector<vector<int>> up(LOG, vector<int>(n));

        int right = 0;
        for (int i = 0; i < n; i++)
        {
            if (right < i)
                right = i;
            while (right + 1 < n && sortedNums[right + 1] - sortedNums[i] <= maxDiff)
                right++;
            up[0][i] = right;
        }

        for (int k = 1; k < LOG; k++)
        {
            for (int i = 0; i < n; i++)
            {
                up[k][i] = up[k - 1][up[k - 1][i]];
            }
        }

        int q = queries.size();
        vector<int> ans(q);
        for (int i = 0; i < q; i++)
        {
            int u = pos[queries[i][0]];
            int v = pos[queries[i][1]];
            if (u > v)
                swap(u, v);

            if (u == v)
            {
                ans[i] = 0;
                continue;
            }

            int cur = u, steps = 0;
            for (int k = LOG - 1; k >= 0; k--)
            {
                if (up[k][cur] < v)
                {
                    cur = up[k][cur];
                    steps += (1 << k);
                }
            }
            ans[i] = (up[0][cur] >= v) ? steps + 1 : -1;
        }

        return ans;
    }
};