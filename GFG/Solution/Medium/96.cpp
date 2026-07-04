class Solution
{
public:
    int maxSumSubarray(vector<int> &arr)
    {
        int n = arr.size();
        vector<int> fwd(n), back(n);
        fwd[0] = arr[0];
        for (int i = 1; i < n; i++)
            fwd[i] = max(arr[i], fwd[i - 1] + arr[i]);
        back[n - 1] = arr[n - 1];
        for (int i = n - 2; i >= 0; i--)
            back[i] = max(arr[i], back[i + 1] + arr[i]);
        int ans = INT_MIN;
        for (int i = 0; i < n; i++)
            ans = max(ans, fwd[i]);
        for (int i = 1; i < n - 1; i++)
            ans = max(ans, fwd[i - 1] + back[i + 1]);
        return ans;
    }
};