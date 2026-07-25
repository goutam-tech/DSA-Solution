/* Structure of Binary Tree Node
class Node {
  public:
    int data;
    Node* left;
    Node* right;

    Node(int val) {
        data = val;
        left = nullptr;
        right = nullptr;
    }
};
*/
class Solution
{
public:
    int ans;

    void solve(Node *node, Node *parent, int len)
    {
        if (!node)
            return;
        int curLen = (parent && node->data == parent->data + 1) ? len + 1 : 1;
        ans = max(ans, curLen);
        solve(node->left, node, curLen);
        solve(node->right, node, curLen);
    }

    int longestConsecutive(Node *root)
    {
        if (!root)
            return -1;
        ans = 1;
        solve(root, nullptr, 0);
        return ans > 1 ? ans : -1;
    }
};