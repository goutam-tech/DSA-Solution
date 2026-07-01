class Solution {
  public:
    int maxValue(vector<int> &arr) {
        // code here
        sort(arr.begin(), arr.end());
        int n = arr.size();
        int mn = arr[0], mx = arr[n - 1];
        
        return 2 * (mx - mn);
    }
};