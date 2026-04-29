public class Solution {
    public IList<string> TwoEditWords(string[] queries, string[] dictionary) {
        var  result = new List<string>();
        foreach(var query in queries){
            foreach(var word in dictionary){
                int diff = 0;
                for(int i = 0; i < query.Length; i++){
                    if(query[i] != word[i]) diff++;
                    if(diff > 2) break;
                }
                if(diff <= 2){
                    result.Add(query);
                    break;
                }
            }
        }
        return result;
    }
}