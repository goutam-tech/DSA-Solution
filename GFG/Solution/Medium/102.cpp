class Solution
{
public:
    int countKdivPairs(vector<int> &arr, int k)
    {
        // code here
        vector<long long> cnt(k, 0);
        for (int x : arr)
        {
            int r = ((x % k) + k) % k;
            cnt[r]++;
        }

        long long ans = 0;

        ans += cnt[0] * (cnt[0] - 1) / 2;

        if (k % 2 == 0)
        {
            ans += cnt[k / 2] * (cnt[k / 2] - 1) / 2;
        }

        for (int r = 1; r < k - r; r++)
        {
            ans += cnt[r] * cnt[k - r];
        }

        return (int)ans;
    }
};