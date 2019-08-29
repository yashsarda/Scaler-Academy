/**
 * Definition for binary tree
 * struct TreeNode {
 *     int val;
 *     TreeNode *left;
 *     TreeNode *right;
 *     TreeNode(int x) : val(x), left(NULL), right(NULL) {}
 * };
 */
int Solution::solve(TreeNode* A, int B, int C) {
}
/**
 * Definition for binary tree
 * struct TreeNode {
 *     int val;
 *     TreeNode *left;
 *     TreeNode *right;
 *     TreeNode(int x) : val(x), left(NULL), right(NULL) {}
 * };
 */
// One of the ideas is to travel the tree in a preorder fashion
// and for every node just check whether the subtree rooted at that node is a BST
// But this solution would take O(n^2) time. O(n) time for travelling in a preorder fashion 
// and for each node O(n) time for finding whether the subtree rooted at that node is BST or not

// Second idea which is more efficient is to use postorder traversal. Why? Because if we knew the 
// answer for both the left and the right subtree then we can construct the answer for the root

// We will require 4 pieces of information
struct Info
{
    bool isBST;
    int size;
    int min_value;
    int max_value;
    
    Info(bool isBST,int size,int min_value,int max_value)
    {
        this -> isBST = isBST;
        this -> size = size;
        this -> min_value = min_value;
        this -> max_value = max_value;
    }
    
};
Info* findLargestBST(TreeNode* root)
{
    if(!root){
        return new Info(true,0,INT_MAX,INT_MIN);
    }
    
    if(!root -> left && !root -> right){
        return new Info(true,1,root -> val, root -> val);
    } 
    
    Info* left = findLargestBST(root -> left);
    Info* right = findLargestBST(root -> right);
    
    Info* current = nullptr;
    if(!(left -> isBST) || !(right -> isBST) || (root -> val < left -> max_value || root -> val >= right -> min_value)) {
        
        //current -> isBST = false;
        //current -> size = max(left -> size, right -> size);
        current = new Info(false, max(left -> size, right -> size), 0, 0);
        //return current;
    }
    else{
    // At this point the tree rooted at root is a BST
        int min_v = root -> left != nullptr ? left -> min_value : root -> val;
        int max_v = root -> right != nullptr ? right -> max_value : root -> val;
        current = new Info(true, left -> size + right -> size + 1, min_v, max_v);
    }
    delete(left);
    delete(right);
    
    return current;
}
int Solution::solve(TreeNode* A) {
    // Corner cases
    if(!A) return 0;
    if(!A -> left && !A -> right) return 1;
    
    Info* ans = findLargestBST(A);
    return ans -> size;
}
