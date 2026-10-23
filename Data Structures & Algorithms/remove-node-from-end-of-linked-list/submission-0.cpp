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
    ListNode* removeNthFromEnd(ListNode* head, int n) {
        ListNode dummy(0);
        ListNode* helper = &dummy;
        ListNode* worker = &dummy;
        dummy.next = head;

        while(n > 0) {
            helper = helper->next;
            n--;
        }

        while(helper->next != nullptr) {
            helper = helper->next;
            worker = worker->next;
        }

        ListNode* nxt = worker->next;
        worker->next = nxt->next;
        nxt->next = nullptr;

        return dummy.next;
    }
};
