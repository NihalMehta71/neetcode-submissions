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
    bool hasCycle(ListNode* head) {
        ListNode* s = head;
        ListNode* f = head;

        while(true) {
            if(s != nullptr && s->next != nullptr)
            s = s->next;
            else {
                return false;
            }

            if(f != nullptr && f->next != nullptr && f->next->next != nullptr)
            f = f->next->next;
            else
            return false;

            if(s == f) return true;

            
        }
        return false;
    }
};
