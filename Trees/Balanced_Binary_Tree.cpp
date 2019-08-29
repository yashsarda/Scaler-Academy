/**
 * Definition for binary tree
 * struct TreeNode {
 *     int val;
 *     TreeNode *left;
 *     TreeNode *right;
 *     TreeNode(int x) : val(x), left(NULL), right(NULL) {}
 * };
 */
bool checkIfBalanced(TreeNode* root,int& height)
{
    int l_sub_h = 0;
    int r_sub_h = 0;
    bool lb,rb;
    lb = rb = false;
    
    if(root == NULL){
        height = 0;
        return true;
    }
    
    lb = checkIfBalanced(root -> left,l_sub_h);
    rb = checkIfBalanced(root -> right,r_sub_h);
    
    height = max(l_sub_h,r_sub_h) + 1;
    if(!lb || !rb)
        return false;
    
    if(abs(l_sub_h - r_sub_h) <= 1)
        return true;
    return false;
}
int Solution::isBalanced(TreeNode* A) {
    int height;
    bool ans = checkIfBalanced(A,height);
    return ans ? 1 : 0;
}
