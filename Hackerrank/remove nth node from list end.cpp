/**
 * Definition for singly-linked list.
 * struct ListNode {
 *     int val;
 *     ListNode *next;
 *     ListNode(int x) : val(x), next(NULL) {}
 * };
 */
ListNode* Solution::removeNthFromEnd(ListNode* A, int B) {
    ListNode* head = A;
    ListNode* temp;
    int size = 0;

    ListNode* ptr1 = A;
    while(ptr1){
        size++;
        ptr1 = ptr1->next;
    }

    if(B >= size){
        temp = head;
        head = head->next;
        free(temp);
        return head;
    }

    int count = 1;
    int val = size - B + 1;
    ptr1 = head;

    while(++count < val){
        ptr1 = ptr1->next;
    }

    temp = ptr1->next;
    ptr1->next = ptr1->next->next;

    return head;
}
