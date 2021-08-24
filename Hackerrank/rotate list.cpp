ListNode* Solution::rotateRight(ListNode* A, int B) {
    ListNode* ptr = A;
    int len=1;
    while(ptr->next!=NULL){
        ptr = ptr->next;
        len++;
    }
    B = B%len;
    if(B==0) return A;
    ListNode* head, *temp, *start = A;
    int i=1; ptr = A;
    while(i<len-B){
        ptr = ptr->next;
        i++;
    }
    head = ptr->next;
    temp = head;
    while(temp->next!=NULL)
        temp = temp->next;
    temp->next = start;
    ptr->next = NULL;
    return head;
}