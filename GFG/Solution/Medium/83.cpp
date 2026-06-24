class Solution
{
public:
    vector<int> constructList(vector<vector<int>> &queries)
    {
        // code here
        vector<int> arr = {0};
        int mask = 0;

        for (auto &q : queries)
        {
            if (q[0] == 1)
            {
                mask ^= q[1];
            }
            else
            {
                arr.push_back(q[1] ^ mask);
            }
        }

        for (int &x : arr)
        {
            x ^= mask;
        }

        sort(arr.begin(), arr.end());
        return arr;
    }
};