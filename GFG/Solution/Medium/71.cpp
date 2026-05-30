#include <map>
#include <queue>
using namespace std;

/* Structure of binary tree node
class Node{
public:
    int data;
    Node* left, right;
    Node(int item)
    {
        data = item;
        left = nullptr;
        right = nullptr;
    }
}
*/
class Solution
{
public:
    vector<int> verticalSum(Node *root)
    {
        // code here
        vector<int> result;
        if (!root)
            return result;

        map<int, int> hdSum;

        queue<pair<Node *, int>> q;
        q.push({root, 0});

        while (!q.empty())
        {
            auto [node, hd] = q.front();
            q.pop();

            hdSum[hd] += node->data;

            if (node->left)
                q.push({node->left, hd - 1});
            if (node->right)
                q.push({node->right, hd + 1});
        }

        for (auto &[hd, sum] : hdSum)
        {
            result.push_back(sum);
        }

        return result;
    }
};