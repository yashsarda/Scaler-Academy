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
ListNode* Solution::reverseList(ListNode* A, int B) {
    ListNode* head = NULL;
    head = reverseK(A,B);
    return head;
}
