class Solution
{
public:
    vector<int> arrayRankTransform(vector<int> &arr)
    {
        vector<int> sorted_arr = arr;
        sort(sorted_arr.begin(), sorted_arr.end());

        unordered_map<int, int> rank;
        int r = 0;
        for (int v : sorted_arr)
        {
            if (!rank.count(v))
                rank[v] = ++r;
        }

        vector<int> res(arr.size());
        for (int i = 0; i < (int)arr.size(); ++i)
        {
            res[i] = rank[arr[i]];
        }

        return res;
    }
};