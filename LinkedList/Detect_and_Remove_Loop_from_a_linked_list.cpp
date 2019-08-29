/**
 * Definition for singly-linked list.
 * struct ListNode {
 *     int val;
 *     ListNode *next;
 *     ListNode(int x) : val(x), next(NULL) {}
 * };
 */
ListNode* Solution::solve(ListNode* A) {
    ListNode* slow = A;
    ListNode* fast = A;
    int number_of_nodes_in_the_loop = 0;
    
    // find the meeting point
    while(fast && fast -> next){
        number_of_nodes_in_the_loop++;
        slow = slow -> next;
        fast = fast -> next -> next;
        if(slow == fast)
            break;
    }
    ListNode* meet = fast;
    slow = A;
    int distance_from_origin = 0;
    // find the origin of the loop
    while(slow != fast){
        distance_from_origin++;
        slow = slow -> next;
        fast = fast -> next;
    }
    distance_from_origin--;
    while(distance_from_origin > 0){
        distance_from_origin--;
        meet = meet -> next;
    }
    
    meet -> next = NULL;
    return A;
}
