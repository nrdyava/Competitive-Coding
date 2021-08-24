/**
 * Definition for singly-linked list.
 * struct ListNode {
 *     int val;
 *     ListNode *next;
 *     ListNode(int x) : val(x), next(NULL) {}
 * };
 */
ListNode* Solution::mergeTwoLists(ListNode* A, ListNode* B) {
    ListNode* head;
    ListNode* ptr = new ListNode(0);
    head = ptr;

    while(A || B){
        if(A != NULL && B != NULL){
            if(A->val <= B->val){
                ptr->next = A;
                A = A->next;
                ptr = ptr->next;
            }
            else{
                ptr->next = B;
                B = B->next;
                ptr = ptr->next;
            }
        }
        else if(A!=NULL){
            ptr->next = A;
            A = A->next;
            ptr = ptr->next;
        }
        else{
            ptr->next = B;
            B = B->next;
            ptr = ptr->next;
        }
    }
    return head->next;
}
