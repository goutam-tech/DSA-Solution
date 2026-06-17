class Solution {
public:
    string mapWordWeights(vector<string>& words, vector<int>& weights) {
        string res;
        res.reserve(words.size());
        for(auto& w : words){
            int sum = 0;
            for(char c : w){
                sum += weights[c - 'a'];
            }
            res += (char)('z' - sum % 26);
        }
        return res;
    }
};