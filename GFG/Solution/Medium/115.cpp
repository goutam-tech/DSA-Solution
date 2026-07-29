/* Structure of Binary Tree Node
class Node {
public:
    int data;
    Node *left;
    Node *right;
    Node(int val) {
        data = val;
        left = right = nullptr;
    }
};*/
class Solution
{
public:
    Node *build(vector<int> &pre, vector<int> &preM, int &idx, int low, int high, int n)
    {
        if (idx >= n || low > high)
            return nullptr;

        Node *root = new Node(pre[idx]);
        idx++;

        if (low == high)
            return root;

        int i = low;
        while (i <= high && preM[i] != pre[idx])
            i++;

        if (i <= high)
        {
            root->left = build(pre, preM, idx, i, high, n);
            root->right = build(pre, preM, idx, low + 1, i - 1, n);
        }

        return root;
    }

    Node *constructBinaryTree(vector<int> &pre, vector<int> &preMirror)
    {
        int n = pre.size();
        int idx = 0;
        return build(pre, preMirror, idx, 0, n - 1, n);
    }
};