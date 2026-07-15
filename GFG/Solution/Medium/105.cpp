class Solution
{
public:
    int maxAmount(vector<int> &arr, int k)
    {
        const int MOD = 1000000007;
        priority_queue<int> pq;
        for (int x : arr)
            pq.push(x);

        long long ans = 0;

        while (k-- && !pq.empty())
        {
            int x = pq.top();
            pq.pop();
            ans = (ans + x) % MOD;
            if (--x > 0)
                pq.push(x);
        }

        return (int)ans;
    }
};