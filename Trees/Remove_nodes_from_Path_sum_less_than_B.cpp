/**
 * Definition for binary tree
 * struct TreeNode {
 *     int val;
 *     TreeNode *left;
 *     TreeNode *right;
 *     TreeNode(int x) : val(x), left(NULL), right(NULL) {}
 * };
 */
// There is a much simpler way to do it
//TC : O(N) (N = number of nodes)
// This utility function calculate the sum upto that node from root and stores it in the map
void precompute(TreeNode* root,unordered_map<TreeNode*,int>& m,int sum)
{
    if(root == NULL)
        return;
    if(root -> left == NULL && root -> right == NULL){
        m[root] = sum + root -> val;
        return;
    }
    precompute(root -> left,m,sum + root -> val);
    precompute(root -> right,m,sum + root -> val);
    
    m[root] = sum + root -> val;
}
// This is postorder even though it's named preorder
// This function calculate the nodes which need to be deleted
// We are going to delete the leaves if their sum < B
// If for a node both of the children is in the set (which means it need to be deleted) then we are also goig to insert
// the node. If the node only has one child and that child is in the set then we are also going to include the node
void preorder(TreeNode* root,unordered_map<TreeNode*,int>& m,set<TreeNode*>& list,int B)
{
    if(root == NULL)
        return;
    if(root -> left == NULL && root -> right == NULL){
        if(m[root] < B)
            list.insert(root);
        return;
    }
    preorder(root -> left,m,list,B);
    preorder(root -> right,m,list,B);
    
    if(root -> left != NULL && root -> right != NULL){
        if(list.find(root -> left) != list.end() && list.find(root -> right) != list.end())
            list.insert(root);
        return;
    }
    
    if(root -> left != NULL){
        if(list.find(root -> left) != list.end())
            list.insert(root);
    }
    
    if(root -> right != NULL){
        if(list.find(root -> right) != list.end())
            list.insert(root);
    }
    
}
// This function delete the nodes stored in the set
TreeNode* postorder(TreeNode* root,set<TreeNode*>& list)
{
    if(root == nullptr)
        return nullptr;
    
    root -> left = postorder(root -> left,list);
    root -> right = postorder(root -> right,list);
    if(list.find(root) != list.end()){
        delete(root);
        list.erase(root);
        return nullptr;
    }
    return root;
}
TreeNode* Solution::solve(TreeNode* A, int B) {
    if(A == NULL)
        return NULL;
    int sum = 0;
    unordered_map<TreeNode*,int> m;
    precompute(A,m,0);
    set<TreeNode*> list;
    preorder(A,m,list,B);
    TreeNode* root = postorder(A,list);
    return root;
}
