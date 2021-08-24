/**
 * Definition for singly-linked list.
 * struct ListNode {
 *     int val;
 *     ListNode *next;
 *     ListNode(int x) : val(x), next(NULL) {}
 * };
 */
ListNode* Solution::reorderList(ListNode* A) {
    if(A == NULL) return A;

    ListNode* ptr1 = A;
    ListNode* ptr2 = A;

    while(ptr2->next && ptr2->next->next){
        ptr1 = ptr1->next;
        ptr2 = ptr2->next->next;
    }

    ptr1 = ptr1->next;
    ptr2 = NULL;
    while(ptr1){
        ListNode* next = ptr1->next;
        ptr1->next = ptr2;
        ptr2 = ptr1;
        ptr1 = next;
    }

    ptr1 = A;
    while(ptr2!=NULL){
        ListNode *next1 = ptr1->next, *next2 = ptr2->next;
        ptr1->next = ptr2;
        ptr2->next = next1;
        ptr1 = next1;
        ptr2 = next2;
    }

    if(ptr1 != NULL) ptr1->next = NULL;

    return A;
}