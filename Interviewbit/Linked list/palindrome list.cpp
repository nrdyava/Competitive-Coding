/**
 * Definition for singly-linked list.
 * struct ListNode {
 *     int val;
 *     ListNode *next;
 *     ListNode(int x) : val(x), next(NULL) {}
 * };
 */
int Solution::lPalin(ListNode* A) {
    ListNode* slow;
    ListNode* fast;
    ListNode* mid;
    ListNode* next;
    ListNode* prev;

    slow = A;
    fast = A;

    while(fast && fast->next){
        slow = slow->next;
        fast = fast->next->next;
    }

    if(fast != NULL){
        mid = slow->next;
    }
    else mid = slow;

    prev = NULL;

    while(mid){
        next = mid->next;
        mid->next = prev;
        prev = mid;
        mid = next;
    }

    while(prev){
        if(A->val != prev->val) return 0;
        prev = prev->next;
        A = A->next;
    }
    return 1;
}
