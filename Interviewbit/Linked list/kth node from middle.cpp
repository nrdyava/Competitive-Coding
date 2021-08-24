/**
 * Definition for singly-linked list.
 * struct ListNode {
 *     int val;
 *     ListNode *next;
 *     ListNode(int x) : val(x), next(NULL) {}
 * };
 */
int Solution::solve(ListNode* A, int B) {
    int size = 1;
    ListNode* temp;
    temp = A;
    while(temp->next != NULL){
        size++;
        temp = temp->next;
    }

    int pos = (size/2) + 1 - B;

    if(pos < 1) return -1;

    int i=1;
    temp = A;

    while(i++ < pos){
        temp = temp->next;
    }
    return temp->val;

}
