/**
 * Definition for binary tree
 * struct TreeNode {
 *     int val;
 *     TreeNode *left;
 *     TreeNode *right;
 *     TreeNode(int x) : val(x), left(NULL), right(NULL) {}
 * };
 */
// Change the left tree in such a way that if the tree was symmetric then after changing the left and right subtree will
// be identical
TreeNode* changeLeftRight(TreeNode* root)
{
    if(root == NULL)
        return NULL;
    
    root -> left = changeLeftRight(root -> left);
    root -> right = changeLeftRight(root -> right);
    
    TreeNode* left = root -> left;
    TreeNode* right = root -> right;
    
    root -> left = right;
    root -> right = left;
    
    return root;
}
bool isIdentical(TreeNode* A,TreeNode* B)
{
    if(A == NULL && B == NULL)
        return true;
    if(A == NULL && B != NULL || B == NULL && A != NULL)
        return false;
    
    bool left = isIdentical(A -> left,B -> left);
    bool right = isIdentical(A -> right,B -> right);
    
    if(!left || !right || A -> val != B -> val)
        return false;
    return true;
        
}
int Solution::isSymmetric(TreeNode* A) {
    if(A == NULL)
        return 1;
    if(!A -> left && !A -> right)
        return 1;
    if(A -> left == NULL && A -> right != NULL)
        return 0;
    if(A -> left && !A->right)
        return 0;
    TreeNode* root = changeLeftRight(A -> left);
    
    return isIdentical(root,A -> right);
}
