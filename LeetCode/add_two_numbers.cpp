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
        ListNode* head = new ListNode;
        ListNode* temp = head;
        int val1 = 0;
        int val2 = 0;
        int carry = 0;
        
        while(l1!=nullptr || l2!= nullptr || carry!=0){
            val1 = (l1!=nullptr)?l1->val:0;
            val2 = (l2!=nullptr)?l2->val:0;
            
            ListNode* newnode = new ListNode;
            newnode->val = (val1 + val2 + carry)%10;
            temp->next = newnode;
            temp = temp->next;
            carry = (val1 + val2 + carry)/10;
            
            l1 = (l1!=nullptr)?l1->next:nullptr;
            l2 = (l2!=nullptr)?l2->next:nullptr;
        }
        return head->next;
        
    }
};