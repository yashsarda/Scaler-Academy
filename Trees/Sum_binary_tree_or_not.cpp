/**
 * Definition for binary tree
 * struct TreeNode {
 *     int val;
 *     TreeNode *left;
 *     TreeNode *right;
 *     TreeNode(int x) : val(x), left(NULL), right(NULL) {}
 * };
 */
bool ifSumTree(TreeNode* root,int& sum)
{
    if(root == NULL){
        sum = 0;
        return true;
    }
    if(root -> left == NULL && root -> right == NULL){
        sum = root -> val;
        return true;
    }
    int leftSum = 0;
    int rightSum = 0;
    
    bool leftans = ifSumTree(root -> left,leftSum);
    bool rightans = ifSumTree(root -> right,rightSum);
    
    sum = leftSum + rightSum;
    
    if(!leftans || !rightans)
        return false;
    if(sum == root -> val){
        sum += root -> val;
        return true;
    }
    return false;
}
int Solution::solve(TreeNode* A) {
    if(A == NULL)
        return 1;
    int sum = 0;
    bool ans = ifSumTree(A,sum);
    return ans;
}
