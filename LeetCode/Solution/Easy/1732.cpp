class Solution
{
public:
    int largestAltitude(vector<int> &gain)
    {
        int cur = 0, best = 0;
        for (int g : gain)
        {
            cur += g;
            best = max(best, cur);
        }
        return best;
    }
};