class Solution {
public:
    string getPermutation(int n, int k) {
        vector<int> numbers;
        for (int i = 1; i <= n; i++) {
            numbers.push_back(i);
        }
        
        vector<int> fact(n+1, 1);
        for (int i = 1; i <= n; i++) {
            fact[i] = fact[i-1] * i;
        }
        
        k--;
        string result = "";
        
        for (int i = n; i >= 1; i--) {
            int index = k / fact[i-1];
            result += to_string(numbers[index]);
            numbers.erase(numbers.begin() + index);
            k %= fact[i-1];
        }
        
        return result;
    }
};