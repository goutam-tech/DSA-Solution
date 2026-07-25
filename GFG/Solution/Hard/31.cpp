class TrieNode
{
public:
    TrieNode *child[26];
    int count;
    TrieNode()
    {
        count = 0;
        for (int i = 0; i < 26; i++)
            child[i] = nullptr;
    }
};

class Solution
{
public:
    void insert(TrieNode *root, const string &word)
    {
        TrieNode *node = root;
        for (char c : word)
        {
            int idx = c - 'a';
            if (!node->child[idx])
                node->child[idx] = new TrieNode();
            node = node->child[idx];
            node->count++;
        }
    }

    string getPrefix(TrieNode *root, const string &word)
    {
        TrieNode *node = root;
        string prefix = "";
        for (char c : word)
        {
            int idx = c - 'a';
            prefix += c;
            node = node->child[idx];
            if (node->count == 1)
                return prefix;
        }
        return prefix;
    }

    vector<string> findPrefixes(vector<string> &arr)
    {
        TrieNode *root = new TrieNode();
        for (auto &word : arr)
            insert(root, word);
        vector<string> res;
        for (auto &word : arr)
            res.push_back(getPrefix(root, word));
        return res;
    }
};