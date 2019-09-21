/**
 * Definition for binary tree
 * struct TreeNode {
 *     int val;
 *     TreeNode *left;
 *     TreeNode *right;
 *     TreeNode(int x) : val(x), left(NULL), right(NULL) {}
 * };
 */
// Great problem
// Find the height of the tree :- O(log n)
// Then binary search on the number on nodes on the last level
void findHeight(TreeNode* root, int& height)
{
    if(!root) 
        return;
    
    if(!root -> left && !root -> right)
        return;
        
    int left_height = 0;
    int right_height = 0;
    
    findHeight(root -> left, left_height);
    findHeight(root -> right, right_height);
    
    height = max(left_height, right_height) + 1;
}
bool checkIfPresent(int number, TreeNode* root, int height)
{
    height--;
    while(height >= 0) {
        int go_in_direction = number / (1 << height);
        if(go_in_direction == 0) {
            if(root -> left)
                root = root -> left;
            else
                return false;
        }
        if(go_in_direction == 1) {
            if(root -> right)
                root = root -> right;
            else
                return false;
        }
        number %= (1 << height);
        height--;
    }
    return true;
}
int Solution::solve(TreeNode* A) {
    if(!A)
        return 0;
    
    if(!A -> left && !A -> right)
        return 1;
    
    int height = 0;
    findHeight(A, height);
    
    int number_of_node_in_last = (1 << height) - 1;
    
    // Binary search on [0, number_of_node_in_last];
    
    int lower = 0;
    int upper = number_of_node_in_last;
    int ans = 0;
    while(lower <= upper) {
        int mid = (lower) + (upper - lower) / 2;
        if(checkIfPresent(mid, A, height)) {
            ans = mid;
            lower = mid + 1;
        }
        else{
            upper = mid - 1;
        }
    }
    return ((1 << height) + ans);
    
}
