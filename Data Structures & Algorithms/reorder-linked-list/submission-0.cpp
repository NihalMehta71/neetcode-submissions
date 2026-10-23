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
    void reorderList(ListNode* head) {
        stack<ListNode*> st;
        ListNode* s = head;
        ListNode* f = head;
        while(f != nullptr && f->next != nullptr) {
            f = f->next->next;
            s = s->next;
        }
        while(s != nullptr) {
            st.push(s);
            s = s->next;
        }

        ListNode* curr = head;
        while(!st.empty()) {
            ListNode* temp = st.top();
            st.pop();

            if (curr == temp) break;

            ListNode* nxt = curr->next;
            curr->next = temp;
            temp->next = nxt;
            curr = nxt;
        }

        if(curr->next != nullptr) curr->next = nullptr;
    }
};
