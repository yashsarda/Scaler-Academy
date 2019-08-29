/**
 * Definition for singly-linked list.
 * struct ListNode {
 *     int val;
 *     ListNode *next;
 *     ListNode(int x) : val(x), next(NULL) {}
 * };
 */
ListNode* Solution::mergeTwoLists(ListNode* A, ListNode* B) {
    ListNode* temp = NULL;
    ListNode* prev = NULL;
    while(A != NULL && B != NULL){
        if(A -> val <= B -> val){
            if(temp == NULL){
                temp = A;
                prev = A;
                A = A -> next;
            }
            else{
                prev -> next = A;
                prev = prev -> next;
                A = A -> next;
            }
        }
        else{
            if(temp == NULL){
                temp = B;
                prev = B;
                B = B -> next;
            }
            else{
                prev -> next = B;
                prev = prev -> next;
                B = B -> next;
            }
        }
    }
    while(A != NULL){
        if(temp == NULL){
                temp = A;
                prev = A;
                A = A -> next;
            }
            else{
                prev -> next = A;
                prev = prev -> next;
                A = A -> next;
            }
    }
    while(B != NULL){
        if(temp == NULL){
                temp = B;
                prev = B;
                B = B -> next;
            }
            else{
                prev -> next = B;
                prev = prev -> next;
                B = B -> next;
            }
    }
    return temp;
}
