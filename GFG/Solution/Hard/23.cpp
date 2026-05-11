class Solution {
  public:
    
    bool isValid(string s){
        int count = 0;
        for (char c : s){
            if (c == '(')
                count++;
            else if (c == ')'){
                count--;
                if (count < 0)
                    return false;
            }
        }
        return count == 0;
    }

    vector<string> validParenthesis(string s){
        unordered_set<string> visited;
        queue<string> q;
        vector<string> result;
    
        q.push(s);
        visited.insert(s);
    
        bool found = false;
    
        while (!q.empty()){
            string curr = q.front();
            q.pop();
            if (isValid(curr)){
                result.push_back(curr);
                found = true;
            }
            if (found)
                continue;
                
            for (int i = 0; i < curr.length(); i++){
                if (curr[i] != '(' && curr[i] != ')')
                    continue;
    
                string next = curr.substr(0, i) + curr.substr(i + 1);
    
                if (visited.find(next) == visited.end()){
                    visited.insert(next);
                    q.push(next);
                }
            }
        }
        return result;
    }
};