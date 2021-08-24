/**
 * Definition for singly-linked list.
 * struct ListNode {
 *     int val;
 *     ListNode *next;
 *     ListNode(int x) : val(x), next(NULL) {}
 * };
 */
ListNode* Solution::reverseBetween(ListNode* A, int B, int C) {
    if(B == C) return A;
    ListNode* ptr1;
    ListNode* ptr2;
    ListNode* ptr3;
    ListNode* ptr4;
    ListNode* dummy = new ListNode(0);
    dummy->next = A;
    ptr1 = dummy;
    ptr2 = dummy;

    int m = 0, n = 0;

    while(m != B-1 || n != C){
        if(m<B-1){
            ptr1 = ptr1->next;
            m++;
        }
        if(n<C){
            ptr2 = ptr2->next;
            n++;
        }
    }
    
    ptr4 = ptr2;
    ptr2 = ptr2->next;
    ptr3 = ptr1->next;

    while(ptr3 != ptr4){
        ptr1->next = ptr3->next;
        ptr4->next = ptr3;
        ptr3->next = ptr2;
        ptr3 = ptr1->next;
        ptr2 = ptr4->next;
    }
    return dummy->next;
}
