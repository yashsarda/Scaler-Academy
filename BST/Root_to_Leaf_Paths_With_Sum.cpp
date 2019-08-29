/**
 * Definition for binary tree
 * struct TreeNode {
 *     int val;
 *     TreeNode *left;
 *     TreeNode *right;
 *     TreeNode(int x) : val(x), left(NULL), right(NULL) {}
 * };
 */
void findAllPaths(TreeNode* root,int required,vector<vector<int> >& ans,vector<int>& intermediate,int sum)
{
    if(root == NULL)
        return;
    if(root -> left == NULL && root -> right == NULL){
        intermediate.push_back(root -> val);
        if(sum == required)
            ans.push_back(intermediate);
        intermediate.pop_back();
        return;
    }
    if(root -> left != NULL){
        intermediate.push_back(root -> left -> val);
        findAllPaths(root -> left,required,ans,intermediate,sum + root ->left->val);
        intermediate.pop_back();
    }
    if(root -> right != NULL){
        intermediate.push_back(root -> right -> val);
        findAllPaths(root -> right,required,ans,intermediate,sum + root -> right -> val);
        intermediate.pop_back();
    }
}
vector<vector<int> > Solution::pathSum(TreeNode* A, int B) {
    vector<vector<int> > ans;
    if(A == nullptr)
        return ans;
    vector<int> intermediate;
    intermediate.push_back(A -> val);
    findAllPaths(A,B,ans,intermediate,A -> val);
    return ans;
}
