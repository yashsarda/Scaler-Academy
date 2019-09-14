/**
 * Definition for binary tree
 * struct TreeNode {
 *     int val;
 *     TreeNode *left;
 *     TreeNode *right;
 *     TreeNode(int x) : val(x), left(NULL), right(NULL) {}
 * };
 */
// print the nodes which are at distance k from root in subtree of root
void findKdown(TreeNode* root, int distance, vector<int>& ans)
{
    if(!root || distance < 0)
        return;
    
    if(distance == 0) {
        ans.push_back(root -> val);
        return;
    }
    
    findKdown(root -> left, distance - 1, ans);
    findKdown(root -> right, distance - 1, ans);
}
int findKnodes(TreeNode* root, int target, int distance, vector<int>& ans)
{
    if(!root)   
        return -1;
    
    if(root -> val == target) {
        findKdown(root,distance,ans);
        return 0;
    }
    
    // find the target node in left subtree
    int distance_left = findKnodes(root -> left, target, distance, ans);
    
    // if we get target node in left subtree then try to find the node which are distance k - dl - 2 in other subtree
    if(distance_left != -1) {
        if(distance_left + 1 == distance) {
            ans.push_back(root -> val);
        }
        else {
            findKdown(root -> right, distance - distance_left - 2, ans);
        }
        return 1 + distance_left;
    }
    
    int distance_right = findKnodes(root -> right, target, distance, ans);
    
    if(distance_right != -1) {
        if(distance_right + 1 == distance) {
            ans.push_back(root -> val);
        }
        else {
            findKdown(root -> left, distance - distance_right - 2, ans);
        }
        return 1 + distance_right;
    }
    
    return -1;
}
vector<int> Solution::solve(TreeNode* A, int B, int C) {
    vector<int> ans;
    if(!A)
        return ans;
    
   int r = findKnodes(A,B,C,ans);
   
   return ans;
}
