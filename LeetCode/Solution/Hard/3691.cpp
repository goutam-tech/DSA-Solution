class Solution {
public:
    long long maxTotalValue(vector<int>& nums, int k) {
        int n = nums.size();
        int LOG = 1;
        while ((1 << LOG) <= n) LOG++;
        vector<vector<int>> mx(LOG, vector<int>(n)), mn(LOG, vector<int>(n));
        for (int i = 0; i < n; i++) mx[0][i] = mn[0][i] = i;
        for (int j = 1; j < LOG; j++)
            for (int i = 0; i + (1<<j) <= n; i++) {
                int a = mx[j-1][i], b = mx[j-1][i+(1<<(j-1))];
                mx[j][i] = nums[a] > nums[b] ? a : b;
                a = mn[j-1][i]; b = mn[j-1][i+(1<<(j-1))];
                mn[j][i] = nums[a] < nums[b] ? a : b;
            }
        auto qmax = [&](int l, int r) {
            int p = __lg(r-l+1);
            int a = mx[p][l], b = mx[p][r-(1<<p)+1];
            return nums[a] > nums[b] ? a : b;
        };
        auto qmin = [&](int l, int r) {
            int p = __lg(r-l+1);
            int a = mn[p][l], b = mn[p][r-(1<<p)+1];
            return nums[a] < nums[b] ? a : b;
        };
        auto val = [&](int l, int r) {
            return nums[qmax(l,r)] - nums[qmin(l,r)];
        };
        using T = tuple<int,int,int>;
        priority_queue<T> pq;
        for (int l = 0; l < n; l++){
            for (int r = l; r < n; r++) {
                pq.push({val(l,r), l, r});
                break;
            }
        }
        priority_queue<T> pq2;
        for (int l = 0; l < n; l++)
            pq2.push({val(l, n-1), l, n-1});
        long long ans = 0;
        while (k--) {
            auto [v, l, r] = pq2.top(); pq2.pop();
            ans += v;
            if (r - 1 >= l) {
                pq2.push({val(l, r-1), l, r-1});
            }
        }
        return ans;
    }
};