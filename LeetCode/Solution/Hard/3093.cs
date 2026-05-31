public class TrieNode{
    public TrieNode[] Children = new TrieNode[26];
    public int BestIdx = -1;
}

public class Solution {
    public int[] StringIndices(string[] wordsContainer, string[] wordsQuery) {
        TrieNode root = new TrieNode();

        for(int idx = 0; idx < wordsContainer.Length; idx++){
            string word = wordsContainer[idx];
            TrieNode node = root;

            if(node.BestIdx == -1 || word.Length < wordsContainer[node.BestIdx].Length){
                node.BestIdx = idx;
            }

            for(int i = word.Length - 1; i >= 0; i--){
                int c = word[i] - 'a';
                if(node.Children[c] == null){
                    node.Children[c] = new TrieNode();
                }
                node = node.Children[c];

                if(node.BestIdx == -1 || word.Length < wordsContainer[node.BestIdx].Length){
                    node.BestIdx = idx;
                }
            }
        }

        int[] ans = new int[wordsQuery.Length];
        for(int i = 0; i < wordsQuery.Length; i++){
            string query = wordsQuery[i];
            TrieNode node = root;

            for(int j = query.Length - 1; j >= 0; j--){
                int c = query[j] - 'a';
                if(node.Children[c] == null) break;
                node = node.Children[c];
            }

            ans[i] = node.BestIdx;
        }

        return ans;
    }
}