/**
 * Definition for singly-linked list.
 * struct ListNode {
 *     int val;
 *     ListNode *next;
 *     ListNode(int x) : val(x), next(NULL) {}
 * };
 */
ListNode* Solution::solve(ListNode* A) {

    ListNode tt = ListNode(0);
    ListNode* head = &tt;
    head->next = A;

    ListNode* ptr1 = head;
    while(ptr1->next && ptr1->next->val==0){
        ptr1 = ptr1->next;
    }

    ListNode* ptr2 = ptr1;

    ListNode* temp1;
    ListNode* temp2;

    while(ptr2->next){  
        if(ptr2->next->val == 0){
            temp1 = ptr2->next;
            temp2 = ptr1->next;
            ptr2->next = ptr2->next->next;
            ptr1->next = temp1;
            ptr1->next->next = temp2;
            ptr1 = ptr1->next;
        }

        else{
            ptr2 = ptr2->next;
        }
    }
    return head->next; 
}
