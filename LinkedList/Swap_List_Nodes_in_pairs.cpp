/**
 * Definition for singly-linked list.
 * struct ListNode {
 *     int val;
 *     ListNode *next;
 *     ListNode(int x) : val(x), next(NULL) {}
 * };
 */

ListNode* reverseK(ListNode* head,int K)
{
    ListNode* prev = NULL;
    ListNode* next = NULL;
    ListNode* curr = head;
    int counterKnodes = 1;
    // Reverse first K nodes
    while(curr != NULL && counterKnodes <= K){
        next = curr -> next;
        curr -> next = prev;
        prev = curr;
        curr = next;
        counterKnodes++;
    }
    
    if(next != NULL)
        head -> next = reverseK(next,K);
    return prev;
}
ListNode* Solution::swapPairs(ListNode* A) {
    if(A == NULL){
        ListNode* temp = NULL;
        return temp;
    }
    if(A -> next == NULL){
        return A;
    }
    ListNode* head = reverseK(A,2);
    return head;
}
