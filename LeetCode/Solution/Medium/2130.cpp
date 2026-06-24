/**
 * Definition for singly-linked list.
 * struct ListNode {
 *     int val;
 *     ListNode *next;
 *     ListNode() : val(0), next(nullptr) {}
 *     ListNode(int x) : val(x), next(nullptr) {}
 *     ListNode(int x, ListNode *next) : val(x), next(next) {}
 * };
 */
class Solution {
public:
    int pairSum(ListNode* head) {
        vector<int> vals;
        while (head != nullptr) {
            vals.push_back(head->val);
            head = head->next;
        }

        int n = vals.size();
        int maxSum = 0;
        for (int i = 0; i < n / 2; i++) {
            int sum = vals[i] + vals[n - 1 - i];
            maxSum = max(maxSum, sum);
        }

        return maxSum;
    }
};