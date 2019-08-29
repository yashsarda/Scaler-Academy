/**
 * Definition for binary tree
 * struct TreeNode {
 *     int val;
 *     TreeNode *left;
 *     TreeNode *right;
 *     TreeNode(int x) : val(x), left(NULL), right(NULL) {}
 * };
 */
vector<int> Solution::postorderTraversal(TreeNode* A) {
    vector<int> v;
    if(A == NULL)
        return v;
    
   /* stack<TreeNode*> st1,st2;
    st1.push(A);
    while(!st1.empty()){
        TreeNode* root = st1.top();
        st1.pop();
        st2.push(root);
        if(root -> left != NULL)
            st1.push(root -> left);
        if(root -> right != NULL)
            st1.push(root -> right);
    }
    while(!st2.empty()){
        v.push_back(st2.top() -> val);
        st2.pop();
    }*/
    
    TreeNode* current = A;
    stack<TreeNode*> st;
    // Current points to the current node
    while(current || !st.empty()){
        // If current is not null then push it onto the stack and go to its left child
        if(current){
           st.push(current);
           current = current -> left;
        }
        else{
            // If current is NULL, then it means it does not have a left child, check whether it has a right child
            // If it has right child set current node to the right child
            TreeNode* t = st.top();
            if(t -> right == NULL){
                // If it does not have a right child then it's a leaf node so pop from the stack
                v.push_back(t -> val);
                st.pop();
                // Tricky Part: If the popped node is actually the right child of top of stack then it means the right 
                // subtree is already visited so we can also pop node from stack
                while(!st.empty() && st.top()-> right == t){
                    t = st.top();
                    v.push_back(t -> val);
                    st.pop();
                }
            }
            else{
                current = t -> right;
            }
        }
    }
    return v;
}