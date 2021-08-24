/**
 * Definition for singly-linked list.
 * struct ListNode {
 *     int val;
 *     ListNode *next;
 *     ListNode(int x) : val(x), next(NULL) {}
 * };
 */
ListNode* Solution::deleteDuplicates(ListNode* A) {
    if(A == NULL) return NULL;

    ListNode* ptr = A;

    while(ptr->next){
        if(ptr->next->val == ptr->val){
            ptr->next = ptr->next->next;
        }
        else ptr = ptr->next;
    }
    return A;

}
