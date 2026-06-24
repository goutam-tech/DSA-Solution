#include <bits/stdc++.h>
#include <sstream>
using namespace std;

class Solution {
  public:
    int binarySearchable(vector<int>& arr) {
        int n = arr.size();
        int cnt = 0;
        function<void(int,int,int,int)> solve = [&](int l, int r, int lo, int hi) {
            if (l > r) return;
            int mid = (l + r) / 2;
            if (arr[mid] > lo && arr[mid] < hi) {
                cnt++;
                solve(l, mid-1, lo, arr[mid]);
                solve(mid+1, r, arr[mid], hi);
            } else {
                int val = arr[mid];
                if (val <= lo) {
                    solve(mid+1, r, lo, hi);
                } else {
                    solve(l, mid-1, lo, hi);
                }
            }
        };
        solve(0, n-1, INT_MIN, INT_MAX);
        return cnt;
    }
};