class Solution
{
public:
    vector<int> gcdValues(vector<int> &nums, vector<long long> &queries)
    {
        int M = *max_element(nums.begin(), nums.end());
        vector<int> freq(M + 1, 0);
        for (int v : nums)
        {
            freq[v]++;
        }

        vector<int> cntMultiples(M + 1, 0);
        for (int g = 1; g <= M; g++)
        {
            int c = 0;
            for (int m = g; m <= M; m += g)
            {
                c += freq[m];
            }
            cntMultiples[g] = c;
        }

        vector<long long> exact(M + 1, 0);
        for (int g = M; g >= 1; g--)
        {
            long long c = cntMultiples[g];
            long long pairs = c * (c - 1) / 2;
            for (int m = 2 * g; m <= M; m += g)
            {
                pairs -= exact[m];
            }
            exact[g] = pairs;
        }

        vector<long long> prefix(M + 1, 0);
        for (int g = 1; g <= M; g++)
        {
            prefix[g] = prefix[g - 1] + exact[g];
        }

        vector<int> ans(queries.size());
        for (size_t i = 0; i < queries.size(); i++)
        {
            long long x = queries[i] + 1;
            int g = int(lower_bound(prefix.begin(), prefix.end(), x) - prefix.begin());
            ans[i] = g;
        }
        return ans;
    }
};