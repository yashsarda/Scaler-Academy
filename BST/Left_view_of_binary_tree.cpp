/*
 * Definition for binary tree
 * struct TreeNode {
 *     int val;
 *     TreeNode *left;
 *     TreeNode *right;
 *     TreeNode(int x) : val(x), left(NULL), right(NULL) {}
 * };
 */
void leftView(TreeNode* root,vector<int>& ans,int level,int& max_level)
{
    if(root == NULL)
        return;
    if(level > max_level){
        max_level = level;
        ans.push_back(root -> val);
    }
    leftView(root -> left,ans,level + 1,max_level);
    leftView(root -> right,ans,level + 1,max_level);
    return ;
}
vector<int> Solution::solve(TreeNode* A) {
    
    vector<int> ans;
    if(A == NULL)
        return ans;
    ans.push_back(A -> val);
    int level = 0;
    int max_level = 0;
    leftView(A,ans,level,max_level);
    return ans;
}
