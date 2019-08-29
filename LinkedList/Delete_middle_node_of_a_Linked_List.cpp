/**
 * Definition for singly-linked list.
 * struct ListNode {
 *     int val;
 *     ListNode *next;
 *     ListNode(int x) : val(x), next(NULL) {}
 * };
 */
ListNode* Solution::solve(ListNode* A) {
    int counter = 0;
    ListNode* temp = A;
    while(temp !=  NULL){
        counter++;
        temp = temp -> next; 
    }
    if(counter == 1){
        ListNode* temp = NULL;
        delete A;
        return temp;
    }
    int middle = counter / 2 + 1;
    ListNode* prev = NULL;
    ListNode* curr = A;
    counter = 1;
    while(counter < middle){
        counter++;
        prev = curr;
        curr = curr -> next;
    }
    
    prev -> next = curr -> next;
    delete curr;
    return A;
}
