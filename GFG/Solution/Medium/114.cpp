class Solution
{
public:
    vector<vector<int>> levelSort(vector<int> &arr)
    {
        int n = arr.size();
        vector<vector<int>> res;
        if (n == 0)
            return res;

        int levelStart = 0, levelSize = 1;
        while (levelStart < n)
        {
            vector<int> level;
            for (int i = 0; i < levelSize && levelStart + i < n; i++)
            {
                level.push_back(arr[levelStart + i]);
            }
            sort(level.begin(), level.end());
            res.push_back(level);
            levelStart += levelSize;
            levelSize *= 2;
        }
        return res;
    }
};