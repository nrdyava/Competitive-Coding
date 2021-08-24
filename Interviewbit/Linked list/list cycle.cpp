/**
 * Definition for singly-linked list.
 * struct ListNode {
 *     int val;
 *     ListNode *next;
 *     ListNode(int x) : val(x), next(NULL) {}
 * };
 */
ListNode* Solution::detectCycle(ListNode* A) {
    // Do not write main() function.
    // Do not read input, instead use the arguments to the function.
    // Do not print the output, instead return values as specified
    // Still have a doubt. Checkout www.interviewbit.com/pages/sample_codes/ for more details
    ListNode* slow = A;
    ListNode* fast = A;

    if(A == NULL || A->next == NULL) return A;

    while(fast->next && fast->next->next){
        fast = fast->next->next;
        slow = slow->next;
        
        if(slow == fast) break;

    }

    if(fast->next == NULL || fast->next->next == NULL) return NULL;

    slow = A;

    while(true){
        if(slow == fast) return slow;
        slow = slow->next;
        fast = fast->next;
    }
}
