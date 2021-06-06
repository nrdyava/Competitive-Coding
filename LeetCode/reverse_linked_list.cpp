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
    ListNode* reverseList(ListNode* head) {
        
        if (head == nullptr) return head;
        
        ListNode* ptr1 = head;
        ListNode* ptr2 = head;
        head = nullptr;
        
        while(ptr2!=nullptr){
            ptr2 = ptr2->next;
            ptr1-> next = head;
            head = ptr1;
            ptr1 = ptr2;
        }
        
        return head;
    }
};