class Solution {
public:
    vector<int> sequentialDigits(int low, int high) {
        vector<int> res;
        string digits = "123456789";
        for (int len = 2; len <= 9; len++) {
            for (int i = 0; i + len <= 9; i++) {
                int num = 0;
                for (int j = i; j < i + len; j++) {
                    num = num * 10 + (digits[j] - '0');
                }
                if (num >= low && num <= high) res.push_back(num);
            }
        }
        sort(res.begin(), res.end());
        return res;
    }
};