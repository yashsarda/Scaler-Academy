/**
 * Definition for binary tree
 * struct TreeNode {
 *     int val;
 *     TreeNode *left;
 *     TreeNode *right;
 *     TreeNode(int x) : val(x), left(NULL), right(NULL) {}
 * };
 */
void countAllPaths(TreeNode* root,vector<vector<int> >& ans,vector<int>& intermediate)
{
    if(root == NULL)
        return;
    intermediate.push_back(root -> val);
    if(root -> left == NULL && root -> right == NULL){
        ans.push_back(intermediate);
        intermediate.pop_back();
        return;
    }
    
    countAllPaths(root -> left,ans,intermediate);
    countAllPaths(root -> right,ans,intermediate);
    intermediate.pop_back();
    return;
}
vector<vector<int> > Solution::solve(TreeNode* A) {
    vector<vector<int> > ans;
    if(A == NULL)
        return ans;
    vector<int> intermediate;
    countAllPaths(A,ans,intermediate);
    return ans;
}
