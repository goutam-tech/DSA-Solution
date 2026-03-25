using System.Text;

class Solution {
    public string findOrder(string[] words) {
        var adj = new Dictionary<char, HashSet<char>>();
        var inDegree = new Dictionary<char,int>();
        
        foreach(string word in words){
            foreach(char c in word){
                if(!adj.ContainsKey(c)) adj[c] = new HashSet<char>();
                if(!inDegree.ContainsKey(c)) inDegree[c] = 0;
            }
        }
        
        for(int i = 0; i< words.Length - 1; i++){
            string w1 = words[i];
            string w2 = words[i + 1];
            int minLen = Math.Min(w1.Length, w2.Length);
            bool foundDiff = false;
            
            for(int j = 0; j < minLen; j++){
                if(w1[j] != w2[j]){
                    if(!adj[w1[j]].Contains(w2[j])){
                        adj[w1[j]].Add(w2[j]);
                        inDegree[w2[j]]++;
                    }
                    foundDiff = true;
                    break;
                }
            }
            
            if(!foundDiff && w1.Length > w2.Length){
                return "";
            }
        }
        
        var queue = new Queue<char>();
        foreach(var kvp in inDegree){
            if(kvp.Value == 0){
                queue.Enqueue(kvp.Key);
            }
        }
        
        var result = new System.Text.StringBuilder();
        
        while(queue.Count > 0){
            char c = queue.Dequeue();
            result.Append(c);
            
            foreach(char neighbor in adj[c]){
                inDegree[neighbor]--;
                if(inDegree[neighbor] == 0){
                    queue.Enqueue(neighbor);
                }
            }
        }
            
        if(result.Length != inDegree.Count){
            return "";
        }
            
        return result.ToString();
    }
}