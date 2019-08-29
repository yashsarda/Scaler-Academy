/**
 * Definition for singly-linked list.
 * struct ListNode {
 *     int val;
 *     ListNode *next;
 *     ListNode(int x) : val(x), next(NULL) {}
 * };
 */
ListNode* Solution::solve(ListNode* A, ListNode* B, int C, int D) {
    // If the second list is empty just return NULL
    if(B == NULL)
        return NULL;
    int counter = 0;
    // Fnd the previous node and the node right after it
    ListNode* prev = NULL;
    ListNode* curr1 = A;
    ListNode* curr2 = B;
    while(counter != C){
        counter++;
        prev = curr1;
        curr1 = curr1 -> next;
    }
    // If previous == NULL then we need to replace the first node of A with B
    // CHnage the head else change the next pointer of prev to poin to the first node of the B
    if(prev == NULL)
        A = curr2;
    else
        prev -> next = curr2;
    // Go to the last node of A in range [C,D]
    while(counter != D){
        counter++;
        curr1 = curr1 -> next;
    }
    // Go to the loast node of B
    while(curr2 -> next != NULL)
        curr2 = curr2 -> next;
    // Just change the next of B to point ot the node after D
    curr2 -> next = curr1 -> next;
    return A;
}
