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
    ListNode* addTwoNumbers(ListNode* l1, ListNode* l2) {
        ListNode* head = nullptr;
        ListNode* tail = nullptr;

        int carry = 0;
        while(l1 != nullptr || l2 != nullptr || carry != 0) {

            int d1 = (l1 != nullptr)? l1->val: 0;
            int d2 = (l2 != nullptr)? l2->val: 0;

            int sum = d1 + d2 + carry;

            carry = sum / 10;
            int digit = sum % 10;

            ListNode* temp = new ListNode(digit);

            if(head == nullptr) {
                head = temp;
                tail = temp;
            }
            else {
                tail->next = temp;
                tail = temp;
            }

            if(l1 != nullptr) {
                l1 = l1->next;
            }

            if(l2 != nullptr) {
                l2 = l2->next;
            }
        }

        return head;
    }
};
