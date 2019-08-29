/**
 * Definition for binary tree
 * struct TreeNode {
 *     int val;
 *     TreeNode *left;
 *     TreeNode *right;
 *     TreeNode(int x) : val(x), left(NULL), right(NULL) {}
 * };
 */
 
/*TreeNode* first;   
TreeNode* last;
TreeNode* previous;*/
// Either declare the variables global or pass by reference
void findSwapNode(TreeNode* root,TreeNode*& previous,TreeNode*& first,TreeNode*& last)
{
    if(!root)
        return;
    
    findSwapNode(root -> left,previous,first,last);
    
    if(previous){
        if(previous -> val > root -> val){
            if(!first)
                first = previous;
            last = root;
        }
    }
    previous = root;
    
    findSwapNode(root -> right,previous,first,last);
}
vector<int> Solution::recoverTree(TreeNode* A) {
    vector<int> ans;
    if(A == NULL)
        return ans;
    TreeNode* first;   
    TreeNode* last;
    TreeNode* previous;
    first = NULL; last = NULL; previous = NULL;
    findSwapNode(A,previous,first,last);
    ans.push_back(last -> val);
    ans.push_back(first -> val);
    
    return ans;
    
}
