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
    ListNode* removeElements(ListNode* head, int val) {
        ListNode* ptr = head;
        ListNode* temp = NULL;
        
        while(head!=NULL && head->val == val){
            head = head->next;
            delete ptr;
            ptr = head;
        }
        
        while(ptr!=NULL && ptr->next!=NULL){
            if (ptr->next->val == val){
                temp = ptr->next;
                ptr->next = ptr->next->next;
                delete temp;
            }
            else ptr = ptr->next;
        }
        return head;
    }
};