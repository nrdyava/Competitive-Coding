/**
 * Definition for singly-linked list.
 * struct ListNode {
 *     int val;
 *     ListNode *next;
 *     ListNode(int x) : val(x), next(NULL) {}
 * };
 */
class Solution {
public:
    bool hasCycle(ListNode *head) {
        struct ListNode *ptr1,*ptr2;
        ptr1=head;
        ptr2=head;
        while(ptr1!=NULL&&ptr1->next!=NULL)
        {
            ptr2=ptr2->next;
            ptr1=ptr1->next->next;
            if(ptr2==ptr1)return true;
        }
        return false;
    }
};