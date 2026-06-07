class Solution {
public:
    vector<bool> getResults(vector<vector<int>>& queries) {
        int n = queries.size();
        vector<int> coords = {0};
        for (auto& q : queries) coords.push_back(q[1]);
        sort(coords.begin(), coords.end());
        coords.erase(unique(coords.begin(), coords.end()), coords.end());
        int m = coords.size();

        auto getIdx = [&](int v) {
            return (int)(lower_bound(coords.begin(), coords.end(), v) - coords.begin());
        };

        vector<int> seg(4 * m, 0);

        function<void(int,int,int,int,int)> update = [&](int node, int lo, int hi, int pos, int val) {
            if (lo == hi) { seg[node] = val; return; }
            int mid = (lo + hi) / 2;
            if (pos <= mid) update(2*node, lo, mid, pos, val);
            else update(2*node+1, mid+1, hi, pos, val);
            seg[node] = max(seg[2*node], seg[2*node+1]);
        };

        function<int(int,int,int,int,int)> query = [&](int node, int lo, int hi, int l, int r) -> int {
            if (r < lo || hi < l) return 0;
            if (l <= lo && hi <= r) return seg[node];
            int mid = (lo + hi) / 2;
            return max(query(2*node, lo, mid, l, r), query(2*node+1, mid+1, hi, l, r));
        };

        set<int> obs;
        obs.insert(0);
        update(1, 0, m-1, getIdx(0), 0);

        vector<bool> results;
        for (auto& q : queries) {
            if (q[0] == 1) {
                int x = q[1];
                auto it = obs.insert(x).first;
                auto nxt = next(it);
                auto prv = prev(it);
                if (nxt != obs.end()) {
                    update(1, 0, m-1, getIdx(*nxt), *nxt - x);
                }
                update(1, 0, m-1, getIdx(x), x - *prv);
            } else {
                int x = q[1], sz = q[2];
                auto it = obs.upper_bound(x);
                --it;
                int gap = x - *it;
                int maxGap = max(gap, query(1, 0, m-1, 0, getIdx(*it)));
                results.push_back(maxGap >= sz);
            }
        }
        return results;
    }
};