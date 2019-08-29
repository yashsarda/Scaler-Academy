/**
 * Definition for binary tree
 * struct TreeNode {
 *     int val;
 *     TreeNode *left;
 *     TreeNode *right;
 *     TreeNode(int x) : val(x), left(NULL), right(NULL) {}
 * };
 */
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
int Solution::isSameTree(TreeNode* A, TreeNode* B) {
    if(A == NULL && B == NULL)
        return 1;
    
    return isIdentical(A,B);
}
