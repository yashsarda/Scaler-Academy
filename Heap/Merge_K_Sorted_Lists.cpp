/**
 * Definition for singly-linked list.
 * struct ListNode {
 *     int val;
 *     ListNode *next;
 *     ListNode(int x) : val(x), next(NULL) {}
 * };
 */
 
struct doub
{
    ListNode* node;
    int index;
};
struct comp
{
    bool operator()(doub const& A,doub const& B)
    {
        return A.node -> val > B.node -> val;
    }
};
ListNode* Solution::mergeKLists(vector<ListNode*> &A) {
    // Do not write main() function.
    // Do not read input, instead use the arguments to the function.
    // Do not print the output, instead return values as specified
    // Still have a doubt. Checkout www.interviewbit.com/pages/sample_codes/ for more details
    
    int k = A.size();
    if(k == 1)
        return A[0];
    
    priority_queue<doub,vector<doub>,comp > pq;
    for(int i=0;i<k;i++){
        doub x;
        x.node = A[i];
        x.index = i;
        pq.push(x);
    }
    ListNode* head = NULL;
    ListNode* temp = NULL;
    while(!pq.empty()){
        doub d = pq.top();
        pq.pop();
        if(!head){
            head = d.node;
            temp = d.node;
        }
        else{
            temp -> next = d.node;
            temp = d.node;
        }
        if(!temp -> next)
            continue;
        doub t;
        t.node = temp -> next;
        t.index = d.index;
        pq.push(t);
    }
    
    
    return head;
    
    
}
