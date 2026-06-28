class Solution
{
public:
    int maxPeopleDefeated(int p)
    {
        // Code Here
        long long P = p;
        long long lo = 0, hi = 200000;
        while (lo < hi)
        {
            long long mid = (lo + hi + 1) / 2;
            long long sum = mid * (mid + 1) * (2 * mid + 1) / 6;
            if (sum <= P)
                lo = mid;
            else
                hi = mid - 1;
        }

        return (int)lo;
    }
};