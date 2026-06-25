class Solution {
public:
    int countMajoritySubarrays(vector<int>& nums, int target) {
        int n = nums.size();
        vector<int> prefix(n + 1, 0);
        for(int i = 1; i <= n; i++){
            prefix[i] = prefix[i - 1] + (nums[i - 1] == target ? 1 : -1);
        }
        int offset = n + 2;
        int size = 2 * n + 5;
        vector<long long> tree(size, 0);
        auto update = [&](int pos){
            for( ; pos < size; pos += pos & (-pos)){
                tree[pos]++;
            }
        };
        auto query = [&](int pos){
            long long s = 0;
            for( ; pos > 0; pos -= pos & (-pos)){
                s += tree[pos];
            }
            return s;
        };

        long long ans = 0;
        update(prefix[0] + offset);
        for(int j = 1; j <= n; j++){
            int val = prefix[j] + offset;
            ans += query(val - 1);
            update(val);
        }
        return (int)ans;
    }
};