using System;

public class SegmentTree {
    private long[] tree;
    private int n;

    public SegmentTree(int n) {
        this.n = n;
        tree = new long[4 * n + 1];
    }

    private long Pull(long a, long b) {
        return Math.Max(a, b);
    }

    private long Query(int u, int l, int r, int tl, int tr) {
        if (r < tl || l > tr) return 0; // neutral for max
        if (tl <= l && r <= tr) return tree[u];

        int m = (l + r) / 2;
        return Pull(
            Query(2 * u, l, m, tl, tr),
            Query(2 * u + 1, m + 1, r, tl, tr)
        );
    }

    public long Query(int l, int r) {
        if (l > r) return 0;
        return Query(1, 0, n - 1, l, r);
    }

    private void Update(int u, int l, int r, int pos, long val) {
        if (l == r) {
            tree[u] = Math.Max(tree[u], val);
            return;
        }

        int m = (l + r) / 2;
        if (pos <= m) Update(2 * u, l, m, pos, val);
        else Update(2 * u + 1, m + 1, r, pos, val);

        tree[u] = Pull(tree[2 * u], tree[2 * u + 1]);
    }

    public void Update(int pos, long val) {
        Update(1, 0, n - 1, pos, val);
    }
}

public class Solution {
    public long MaxAlternatingSum(int[] nums, int k) {
        int n = nums.Length;

        int mx = 0;
        foreach (int x in nums) {
            if (x > mx) mx = x;
        }

        SegmentTree seg0 = new SegmentTree(mx + 1);
        SegmentTree seg1 = new SegmentTree(mx + 1);

        long[] ans0 = new long[n];
        long[] ans1 = new long[n];

        long res = 0;

        // iterate from end
        for (int i = n - 1; i >= 0; i--) {
            if (i + k < n) {
                seg0.Update(nums[i + k], ans0[i + k]);
                seg1.Update(nums[i + k], ans1[i + k]);
            }

            // next greater
            ans0[i] = nums[i] + seg1.Query(nums[i] + 1, mx);

            // next smaller
            ans1[i] = nums[i] + seg0.Query(1, nums[i] - 1);

            res = Math.Max(res, Math.Max(ans0[i], ans1[i]));
        }

        return res;
    }
}