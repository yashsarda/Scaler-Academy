/**
 * Definition for binary tree with next pointer.
 * struct TreeLinkNode {
 *  int val;
 *  TreeLinkNode *left, *right, *next;
 *  TreeLinkNode(int x) : val(x), left(NULL), right(NULL), next(NULL) {}
 * };
 */
TreeLinkNode* next(TreeLinkNode* root)
{
    root = root -> next;
    while(root) {
        if(root -> left)
            return root -> left;
        if(root -> right)
            return root -> right;
        
        root = root -> next;
    }
    return root;
}
void Solution::connect(TreeLinkNode* A) {
    if(!A)
        return;
    if(!A -> left && !A -> right){
        A -> next = NULL;
        return;
    }
    // the p pointer is used to travel to successive levels
    TreeLinkNode* p = A;
    // the q pointer is used to travel the specific level
    TreeLinkNode* q;
    
    while(p){
        q = p;
        while(q) {
            if(q -> left) {
                q -> left -> next = q -> right ? q -> right : next(q);
            }
            
            if(q -> right) {
                q -> right -> next = next(q);
            }
            
            q = q -> next;
        }
        
        if(p -> left)
            p = p -> left;
        else if(p -> right)
            p = p -> right;
        else
            p = next(p);
    }
    
    return;
}
/**
 * Definition for binary tree with next pointer.
 * struct TreeLinkNode {
 *  int val;
 *  TreeLinkNode *left, *right, *next;
 *  TreeLinkNode(int x) : val(x), left(NULL), right(NULL), next(NULL) {}
 * };
 */
TreeLinkNode* next(TreeLinkNode* root)
{
    root = root -> next;
    while(root) {
        if(root -> left)
            return root -> left;
        if(root -> right)
            return root -> right;
        
        root = root -> next;
    }
    return root;
}
void Solution::connect(TreeLinkNode* A) {
    if(!A)
        return;
    if(!A -> left && !A -> right){
        A -> next = NULL;
        return;
    }
    // the p pointer is used to travel to successive levels
    TreeLinkNode* p = A;
    // the q pointer is used to travel the specific level
    TreeLinkNode* q;
    
    while(p){
        q = p;
        while(q) {
            if(q -> left) {
                q -> left -> next = q -> right ? q -> right : next(q);
            }
            
            if(q -> right) {
                q -> right -> next = next(q);
            }
            
            q = q -> next;
        }
        
        if(p -> left)
            p = p -> left;
        else if(p -> right)
            p = p -> right;
        else
            p = next(p);
    }
    
    return;
}
