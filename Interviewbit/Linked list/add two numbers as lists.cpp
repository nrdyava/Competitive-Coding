/**
 * Definition for singly-linked list.
 * struct ListNode {
 *     int val;
 *     ListNode *next;
 *     ListNode(int x) : val(x), next(NULL) {}
 * };
 */
ListNode* Solution::addTwoNumbers(ListNode* A, ListNode* B) {
    ListNode* head = new ListNode(0);
    ListNode* ptr = head;
    int carry = 0;
    int sum;

    while(A || B || carry){
        sum = 0;
        sum += (A)?A->val:0;
        sum += (B)?B->val:0;
        sum += carry; 

        ptr ->next = new ListNode(sum%10);
        carry = sum/10;
        ptr = ptr->next;

        A = (A)?A->next:NULL;
        B = (B)?B->next:NULL;
    }
    return head->next;
}
