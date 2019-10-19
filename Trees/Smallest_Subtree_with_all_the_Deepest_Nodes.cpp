/**
 * Definition for binary tree
 * struct TreeNode {
 *     int val;
 *     TreeNode *left;
 *     TreeNode *right;
 *     TreeNode(int x) : val(x), left(NULL), right(NULL) {}
 * };
 */
// LCA of all nodes which are at maximum depth
// 1. Find the nodes which are max depth
unordered_map<TreeNode* ,int> depth;
void dfs(TreeNode* current, int d)
{
    if(!current) return;
    
    depth[current] = d + 1;
    dfs(current -> left, d + 1);
    dfs(current -> right, d + 1);
}
TreeNode* final_answer(TreeNode* root, int max_depth)
{
    // if we are at a null node or at node which is at the deepest level then
    // directly return that node
    if(!root || depth[root] == max_depth)
        return root;
    
    TreeNode* left = final_answer(root -> left, max_depth);
    TreeNode* right = final_answer(root -> right, max_depth);
    
   // if both the left and right subtree node are not null, then the current root is answer
   if(left && right) return root;
   // if left is not null then left subtree node will be the answer and similarly for right 
   if(left) return left;
   if(right) return right;
   
   return nullptr;
}
TreeNode* Solution::solve(TreeNode* A) {
    depth.clear();
    TreeNode* root = A;
    if(!root) return root;
    if(!root -> left && !root -> right) return root;
    
    // find maximum depth using this dfs
    dfs(root, -1);
    int max_depth = -1;
    
    for(auto it=depth.begin();it!=depth.end();it++) {
        max_depth = max(max_depth, it -> second);
    }

    return final_answer(root,max_depth);
}
