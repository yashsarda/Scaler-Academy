/**
 * Definition for binary tree
 * struct TreeNode {
 *     int val;
 *     TreeNode *left;
 *     TreeNode *right;
 *     TreeNode(int x) : val(x), left(NULL), right(NULL) {}
 * };
 */

int min_depth(TreeNode* root)
{
    if(!root)
        return 0;
    
    if(!root -> left && !root -> right)
        return 1;
        
     
    int left = min_depth(root -> left);
    int right = min_depth(root -> right);
    
    if(root -> left && root -> right)
        return min(left,right) + 1;
    
    if(root -> left && !root -> right || root -> right && !root -> left)
        return max(left,right) + 1;
    
}
int Solution::minDepth(TreeNode* A) {
    
    if(!A)
        return 0;
    
    if(!A -> left && !A -> right)
        return 1;
    
    int min_d = min_depth(A);
    return min_d;
}
