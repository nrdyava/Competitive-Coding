/**
 * Definition for singly-linked list.
 * struct ListNode {
 *     int val;
 *     ListNode *next;
 *     ListNode(int x) : val(x), next(NULL) {}
 * };
 */
ListNode* Solution::deleteDuplicates(ListNode* A) {
    ListNode* Dummy = new ListNode(0);
    ListNode* head = A;
    Dummy->next = head;
    ListNode* prev = Dummy;

    while(head){
        if(head->next && head->val == head->next->val){
            while(head->next && head->val == head->next->val){
                head = head->next;
            }
            prev->next = head->next;
        }
        else prev = prev->next;
        head = head->next;
    }
    return Dummy->next; 
}
