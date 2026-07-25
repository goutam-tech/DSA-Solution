class Solution
{
public:
    bool ok(long long x, vector<int> &arr, int maxA)
    {
        for (int a : arr)
        {
            x = 2 * x - a;
            if (x < 0)
                return false;
            if (x >= maxA)
                return true;
        }
        return true;
    }

    int find(vector<int> &arr)
    {
        int maxA = *max_element(arr.begin(), arr.end());
        long long lo = 1, hi = maxA;
        while (lo < hi)
        {
            long long mid = lo + (hi - lo) / 2;
            if (ok(mid, arr, maxA))
                hi = mid;
            else
                lo = mid + 1;
        }
        return (int)lo;
    }
};