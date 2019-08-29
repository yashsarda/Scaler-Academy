/**
 * Definition for binary tree
 * struct TreeNode {
 *     int val;
 *     TreeNode *left;
 *     TreeNode *right;
 *     TreeNode(int x) : val(x), left(NULL), right(NULL) {}
 * };
 */
vector<int> Solution::inorderTraversal(TreeNode* A) {
        vector<int> v;
    if(A == NULL)
        return v;
    TreeNode* root = A;
    stack<TreeNode*> st;  
    while(root != NULL){
        st.push(root);
        root = root -> left;
    }
    while(!st.empty()){
        TreeNode* t = st.top();
        st.pop();
        v.push_back(t -> val);
        TreeNode* righ = t -> right;
        if(righ == NULL)
            continue;
        while(righ != NULL){
            st.push(righ);
            righ = righ -> left;
        }
    }
}
