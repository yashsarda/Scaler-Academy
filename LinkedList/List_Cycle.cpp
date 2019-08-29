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
    if(A == NULL)
        return NULL;
    if(A -> next == NULL)
        return NULL;
        
    ListNode* slow = A;
    ListNode* fast = A;
    while(fast != NULL && fast -> next != NULL){
        slow = slow -> next;
        fast = fast -> next -> next;
        if(fast == slow)
            break;
    }
    if(fast == NULL || fast -> next == NULL)
        return NULL;
    ListNode* slow1 = A;
    ListNode* slow2 = slow;
    while(slow1 -> val != slow2 -> val){
        slow1 = slow1 -> next;
        slow2 = slow2 -> next;
    }
    return slow1;
}
