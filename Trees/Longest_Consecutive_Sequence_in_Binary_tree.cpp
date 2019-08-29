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
    
    if(!A -> left && !A -> right) return 1;
    
    //level order traversal should solve the problem
    
    queue<TreeNode*> q;
    q.push(A);
    map<TreeNode*, int> level;
    level[A] = 1;
    int answer = INT_MIN;
    while(!q.empty()){
        TreeNode* parent = q.front();
        q.pop();
        int pval = parent -> val;
        if(parent -> left){
            int val = parent -> left -> val;
            if(val == pval + 1)
                level[parent -> left] = level[parent] + 1;
            else
                level[parent -> left] = 1;
            answer = max(answer, level[parent -> left]);
            q.push(parent -> left);
        }
        if(parent -> right){
            int val = parent -> right -> val;
            if(val == pval + 1)
                level[parent -> right] = level[parent] + 1;
            else
                level[parent -> right] = 1;
            answer = max(answer, level[parent -> right]);
            q.push(parent -> right);
        }
    }
    return answer;
}
