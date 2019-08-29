/**
 * Definition for binary tree
 * struct TreeNode {
 *     int val;
 *     TreeNode *left;
 *     TreeNode *right;
 *     TreeNode(int x) : val(x), left(NULL), right(NULL) {}
 * };
 */
vector<int> Solution::preorderTraversal(TreeNode* A) {
    vector<int> v;
    if(A == NULL)
        return v;
    stack<TreeNode*> st;
    st.push(A);
    
    while(!st.empty()){
        TreeNode* x = st.top();
        st.pop();
        v.push_back(x -> val);
        if(x -> right != NULL)
            st.push(x -> right);
        if(x -> left != NULL)
            st.push(x -> left);
    }
    return v;
}
