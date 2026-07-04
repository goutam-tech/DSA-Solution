class Solution
{
public:
    int maximumLength(vector<int> &nums)
    {
        unordered_map<long long, int> cnt;
        for (int v : nums)
            cnt[v]++;
        int ans = 0;
        if (cnt.count(1))
        {
            int m = cnt[1];
            ans = (m % 2 == 1) ? m : m - 1;
        }
        for (auto &p : cnt)
        {
            long long k = p.first;
            if (k == 1)
                continue;
            long long cur = k;
            int len = 1;
            while (true)
            {
                long long nxt = cur * cur;
                auto it = cnt.find(nxt);
                if (it == cnt.end())
                    break;
                if (cnt[cur] < 2)
                    break;
                len += 2;
                cur = nxt;
            }
            if (len > ans)
                ans = len;
        }
        return ans;
    }
};