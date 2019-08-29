/**
 * Definition for binary tree
 * struct TreeNode {
 *     int val;
 *     TreeNode *left;
 *     TreeNode *right;
 *     TreeNode(int x) : val(x), left(NULL), right(NULL) {}
 * };
 */

void findKth(TreeNode* root, int& k,int& ans,int B)
{
    if(!root)
        return;
    
    findKth(root -> left, k, ans, B);
    k++;
    
    if(k == B)
        ans = root -> val;
    
    findKth(root -> right, k, ans, B);
}
int Solution::kthsmallest(TreeNode* A, int B) {
    if(!A)
        return 0;
    
    if(!A -> left && !A -> right){
        if(B == 1)
            return A -> val;
        return 0;
    }
    
    int k = 0;
    int ans = 0;
    
    findKth(A,k,ans,B);
    return ans;
}
