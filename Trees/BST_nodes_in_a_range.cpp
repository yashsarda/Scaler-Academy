/**
 * Definition for binary tree
 * struct TreeNode {
 *     int val;
 *     TreeNode *left;
 *     TreeNode *right;
 *     TreeNode(int x) : val(x), left(NULL), right(NULL) {}
 * };
 */
void countNodes(TreeNode* root, int B,int C,int& count)
{
    if(!root)
        return;
    
    countNodes(root -> left, B, C, count);
    if(root -> val >= B && root -> val <= C)
        count++;
    countNodes(root -> right, B, C, count);
}
int Solution::solve(TreeNode* A, int B, int C) {
    if(!A) return 0;
    
    int count = 0;
    countNodes(A,B,C,count);
    return count;
}
