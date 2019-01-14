 struct ListNode {
     int val;
     ListNode *next;
     ListNode(int x) : val(x), next(NULL) {}
 };
class Solution {
public:
    ListNode* removeNthFromEnd(ListNode* head, int n) {
        int dist = n + 1;
        ListNode* p1 = head;
        while (p1 != NULL && dist > 0) {
            p1 = p1->next;
            dist--;
        }
        ListNode *tmp;
        if (dist > 0) {
            tmp = head;
            head = head->next;
            delete tmp;
            return head;
        }
        ListNode* p2 = head;
        while (p1 != NULL) {
            p1 = p1->next;
            p2 = p2->next;
        }
        tmp = p2->next;
        p2->next = tmp->next;
        delete tmp;
        return head;
    }
};