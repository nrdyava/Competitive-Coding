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
    ListNode* deleteDuplicates(ListNode* head) {
        ListNode* headcp = head;
        ListNode* ptr = head;
        if (!head) return head;
        while(true){
            if (ptr->next == nullptr) return headcp;
            else if(ptr->next && ptr->val == ptr->next->val){
                ListNode* temp = ptr->next;
                ptr->next = ptr->next->next;
                delete temp;
            }
            else{
                ptr = ptr->next;
            }
        }
        return headcp;
    }
};