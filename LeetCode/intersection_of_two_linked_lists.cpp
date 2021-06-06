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
    ListNode *getIntersectionNode(ListNode *headA, ListNode *headB) {
        int len1 = 0;
        int len2 = 0;
        int count = 0;
        int skip1 = 0;
        int skip2 = 0;
        
        ListNode* ptr1 = headA;
        ListNode* ptr2 = headB;
        
        if (headA ==NULL && headB==NULL) return NULL; 
        
        while(ptr1!=NULL){
            len1++;
            ptr1=ptr1->next;
        }
        
        while(ptr2!=NULL){
            len2++;
            ptr2=ptr2->next;
        }
        
        skip1 = max(0, len1 - len2);
        skip2 = max(0, len2 - len1);
        
        
        ptr1 = headA;
        ptr2 = headB;
        for (int i=0;i<skip1;i++) ptr1 = ptr1->next;
        for (int i=0;i<skip2;i++) ptr2 = ptr2->next;
        
        while (ptr1 != NULL){
            if (ptr1 == ptr2) return ptr1;
            else{
                ptr1 = ptr1->next;
                ptr2 = ptr2->next;
            }
        }
        
        return NULL;
    }
};