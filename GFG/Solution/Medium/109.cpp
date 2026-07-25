class Solution
{
public:
    vector<bool> processQueries(vector<int> &arr, vector<vector<int>> &queries)
    {
        int n = arr.size();
        vector<int> inc(n), dec(n), maxEnd(n);

        inc[n - 1] = n - 1;
        for (int i = n - 2; i >= 0; i--)
            inc[i] = (arr[i] <= arr[i + 1]) ? inc[i + 1] : i;

        dec[n - 1] = n - 1;
        for (int i = n - 2; i >= 0; i--)
            dec[i] = (arr[i] >= arr[i + 1]) ? dec[i + 1] : i;

        for (int i = 0; i < n; i++)
            maxEnd[i] = dec[inc[i]];

        vector<bool> ans;
        ans.reserve(queries.size());
        for (auto &q : queries)
            ans.push_back(q[1] <= maxEnd[q[0]]);

        return ans;
    }
};