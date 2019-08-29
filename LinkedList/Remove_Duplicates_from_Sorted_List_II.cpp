/**
 * Definition for singly-linked list.
 * struct ListNode {
 *     int val;
 *     ListNode *next;
 *     ListNode(int x) : val(x), next(NULL) {}
 * };
 */
ListNode* Solution::deleteDuplicates(ListNode* A) {
    ListNode* curr = A;
    if(curr == NULL)
        return NULL;
    if(curr -> next == NULL)
        return curr;
    map<int,bool> m;
    while(curr != NULL && curr -> next != NULL){
        if(curr -> val == curr -> next -> val)
            m[curr -> val] = true;
        curr = curr -> next;
    }
    curr = A;
    ListNode* head = NULL;
    ListNode* t = NULL;
    while(curr != NULL){
        ListNode* temp = curr;
        if(m.find(curr -> val) != m.end()){
            delete temp;
        }
        else{
            if(head == NULL){
                head = new ListNode(curr -> val);
                t = head;
            }
            else{
                ListNode* x = new ListNode(curr -> val);
                t -> next = x;
                t = x;
            }
        }
        curr = curr -> next;
    }
    return head;
}
