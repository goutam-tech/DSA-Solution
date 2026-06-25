class Solution
{
public:
    vector<int> optimalArray(vector<int> &arr)
    {
        // code here
        int n = arr.size();
        vector<int> res(n);
        long long S = 0, P = 0;
        int mid = -1;
        for (int i = 0; i < n; i++)
        {
            S += arr[i];
            int newMid = i / 2;
            if (newMid > mid)
            {
                mid = newMid;
                P += arr[mid];
            }
            long long countLeft = mid;
            long long countRight = i - mid;
            long long sumLeft = P - arr[mid];
            long long sumRight = S - P;
            long long cost = (sumRight - countRight * arr[mid]) + (countLeft * arr[mid] - sumLeft);
            res[i] = (int)cost;
        }
        return res;
    }
};