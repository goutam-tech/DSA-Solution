class Solution {
  public:
    vector<int> increasingNumbers(int n) {
        vector<int> result;
        if (n <= 0 || n > 10) 
            return result;
        if (n == 1) {
            for (int d = 0; d <= 9; d++) 
                result.push_back(d);
            return result;
        }
        vector<int> digits;

        function<void(int,int)> backtrack = [&](int start, int count) {
            if (count == n) {
                int num = 0;
                for (int d : digits) 
                    num = num * 10 + d;
                result.push_back(num);
                return;
            }
            for (int d = start; d <= 9; d++) {
                digits.push_back(d);
                backtrack(d + 1, count + 1);
                digits.pop_back();
            }
        };
        
        backtrack(1, 0);
        return result;
    }
};