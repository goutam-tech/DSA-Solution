/* Structure of a Linked List node
class Node {
  public:
    int data;
    Node* next;

    Node(int x) {
        data = x;
        next = nullptr;
    }
};
*/

class Solution {
  public:
    Node *compute(Node *head) {
        Node* rev = nullptr;
        while (head) {
            Node* next = head->next;
            head->next = rev;
            rev = head;
            head = next;
        }
        int maxVal = INT_MIN;
        Node dummy(0);
        dummy.next = rev;
        Node* cur = &dummy;
        while (cur->next) {
            if (cur->next->data < maxVal) {
                cur->next = cur->next->next;
            } else {
                maxVal = cur->next->data;
                cur = cur->next;
            }
        }
        head = nullptr;
        cur = dummy.next;
        while (cur) {
            Node* next = cur->next;
            cur->next = head;
            head = cur;
            cur = next;
        }
        return head;
    }
};