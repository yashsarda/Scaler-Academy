/**
 * Definition for singly-linked list.
 * struct ListNode {
 *     int val;
 *     ListNode *next;
 *     ListNode(int x) : val(x), next(NULL) {}
 * };
 */

ListNode* Solution::partition(ListNode* A, int B) {
    ListNode* smaller = NULL;
    ListNode* equal = NULL;
    ListNode* greater = NULL;
    ListNode* smallernext = NULL; ListNode* greaternext = NULL; ListNode* equalnext = NULL;
    ListNode* curr = A;
    while(curr != NULL){
        if(curr -> val < B){
            if(smaller == NULL)
                smaller= smallernext = curr;
            else{
                smallernext -> next = curr;
                smallernext = curr;
            }
        }
        else if(curr -> val >= B){
            if(greater == NULL)
                greater =  greaternext = curr;
            else{
                greaternext -> next = curr;
                greaternext = curr;
            }
        }
        curr = curr -> next;
    }
    if(greaternext != NULL)
        greaternext -> next = NULL;
    
    if(smaller == NULL){
       return greater;
    }
    
    smallernext -> next = greater;    
    return smaller;
}
