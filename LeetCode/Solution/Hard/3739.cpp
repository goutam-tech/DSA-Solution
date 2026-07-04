class Solution
{
    int n;
    vector<int> bit;

    void update(int x, int delta)
    {
        for (; x <= n; x += x & -x)
        {
            bit[x] += delta;
        }
    }

    int query(int x)
    {
        int s = 0;
        for (; x > 0; x -= x & -x)
        {
            s += bit[x];
        }
        return s;
    }

public:
    long long countMajoritySubarrays(vector<int> &nums, int target)
    {
        int sz = nums.size();
        n = 2 * sz + 1;
        bit.assign(n + 1, 0);

        int s = sz + 1;
        update(s, 1);

        long long ans = 0;
        for (int x : nums)
        {
            s += (x == target) ? 1 : -1;
            ans += query(s - 1);
            update(s, 1);
        }
        return ans;
    }
};