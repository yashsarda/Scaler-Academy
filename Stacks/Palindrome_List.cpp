/**
 * Definition for singly-linked list.
 * struct ListNode {
 *     int val;
 *     ListNode *next;
 *     ListNode(int x) : val(x), next(NULL) {}
 * };
 */
int Solution::lPalin(ListNode* A) {
    // count number of nodes in the LL
    int count = 1;
    ListNode* temp = A;
    while(temp -> next != NULL){
        count++;
        temp = temp -> next;
    }
    // Corner Cases
    if(count == 1)
        return 1;
    if(count == 2){
        if(A -> val == A -> next -> val)
            return 1;
        return 0;
    }
    // Find the middle element of the linked list
    int middle = count / 2;
    if(count & 1)
        middle++;
        
    // Go upto the middle element
   int counter_upto_middle = 1;
    temp = A;
    while(counter_upto_middle < middle){
        temp = temp -> next;
        counter_upto_middle++;
    }
    // Reverse the [middle+1...end] 
    ListNode* prev = temp;
    ListNode* curr = prev -> next;
    while(curr != NULL){
        ListNode* t = curr;
        ListNode* x = curr -> next;
        t -> next = prev;
        prev = t;
        curr = x;
    }
    // Then just check the end pointers
    counter_upto_middle = 1;
    temp = A;
    while(counter_upto_middle < middle){
        if(temp -> val  != prev -> val)
            return 0;
        temp = temp -> next;
        prev = prev -> next;
        counter_upto_middle++;
    }
    if(count % 2 == 0){
        if(temp -> val == prev -> val)
            return 1;
        return 0;
    }
    return 1;
    
    
}
