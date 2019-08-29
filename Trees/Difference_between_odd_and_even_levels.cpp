/**
 * Definition for binary tree
 * struct TreeNode {
 *     int val;
 *     TreeNode *left;
 *     TreeNode *right;
 *     TreeNode(int x) : val(x), left(NULL), right(NULL) {}
 * };
 */
int Solution::solve(TreeNode* A) {
    if(!A) return 0;
    
    int even = 0;
    int odd = 0;
    
    queue<TreeNode*> q;
    map<TreeNode*, int> level;
    q.push(A);
    level[A] = 1;
    
    odd += A -> val;
    while(!q.empty()){
        TreeNode* parent = q.front();
        q.pop();
        
        if(parent -> left){
            level[parent -> left] = level[parent] + 1;
            if(level[parent -> left] & 1)
                odd += parent -> left -> val;
            else
                even += parent -> left -> val;
            q.push(parent -> left);
        }
        
        
        if(parent -> right){
            level[parent -> right] = level[parent] + 1;
            if(level[parent -> right] & 1)
                odd += parent -> right -> val;
            else
                even += parent -> right -> val;
            q.push(parent -> right);
        }
    }
    
    return odd - even;
}
