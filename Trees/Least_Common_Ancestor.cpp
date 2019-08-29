/**
 * Definition for binary tree
 * struct TreeNode {
 *     int val;
 *     TreeNode *left;
 *     TreeNode *right;
 *     TreeNode(int x) : val(x), left(NULL), right(NULL) {}
 * };
 */
TreeNode* LCA(TreeNode* root,int val1,int val2)
{
    if(root == NULL)
        return NULL;
    
    if(root -> val == val1 || root -> val == val2)
        return root;
    
    TreeNode* leftNode = LCA(root -> left,val1,val2);
    TreeNode* rightNode = LCA(root -> right, val1,val2);
    
    if(leftNode == NULL && rightNode == NULL)
        return NULL;
    
     if(leftNode != NULL && rightNode != NULL){
         if(leftNode -> val != rightNode -> val)
            return root;
     }
     if(leftNode != NULL)
        return leftNode;
    
    if(rightNode != NULL)
        return rightNode;
    
}
bool preorder(TreeNode* root,int search)
{
    if(root == NULL)
        return false;
    if(root -> val == search)
        return true;
    return preorder(root -> left,search) || preorder(root -> right,search);
}
int Solution::lca(TreeNode* A, int B, int C) {
    if(A == NULL)
        return -1;
    TreeNode* anc = LCA(A,B,C);
    // If the ancestor is NULL then both the nodes are not prsent in the tree
    if(anc == NULL)
        return -1;
    int value = anc -> val;
    // If one of the nodes match then search for the other node in the tree 
    if(value == B){
       bool search = preorder(A,C);
        if(!search)
           return -1;
        return value;
    }
    if(value == C){
        bool search = preorder(A,B);
            if(!search)
                return -1;
        return value;
    }
    // both nodes are present in the tree
    return value;
}
