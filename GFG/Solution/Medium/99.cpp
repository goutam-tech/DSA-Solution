class Solution {
public:
    int maxPathSum(vector<int> &a, vector<int> &b) {
        // Code here
        int n = a.size(), m = b.size();
        int i = 0, j = 0;
        long long sum1 = 0, sum2 = 0, result = 0;
        while(i < n && j < m){
            if(a[i] < b[j]){
                sum1 += a[i++];
            }
            else if(a[i] > b[j]){
                sum2 += b[j++];
            }
            else{
                result += max(sum1, sum2) + a[i];
                sum1 = 0;
                sum2 = 0;
                i++;
                j++;
            }
        }
        while(i < n) sum1 += a[i++];
        while(j < m) sum2 += b[j++];
        result += max(sum1, sum2);
        return (int)result;
    }
};