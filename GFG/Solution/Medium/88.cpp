class Solution
{
public:
    int maxArea(vector<int> &height)
    {
        int l = 0, r = height.size() - 1;
        int res = 0;
        while (l < r)
        {
            int h = min(height[l], height[r]);
            res = max(res, h * (r - l - 1));
            if (height[l] < height[r])
                l++;
            else
                r--;
        }
        return res;
    }
};