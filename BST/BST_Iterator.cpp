/**
 * Definition for binary tree
 * struct TreeNode {
 *     int val;
 *     TreeNode *left;
 *     TreeNode *right;
 *     TreeNode(int x) : val(x), left(NULL), right(NULL) {}
 * };
 */
TreeNode* Solution::sortedArrayToBST(const vector<int> &A) {
    
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
vector<int> ans;
  stack<int> s;
void inorder(TreeNode* root)
{
    if(root == NULL)
        return;
    inorder(root -> left);
    ans.push_back(root -> val);
    inorder(root -> right);
}
BSTIterator::BSTIterator(TreeNode *root) {
    ans.clear();
    if(root){
        inorder(root);
    }
    for(int i=ans.size() - 1;i>=0;i--){
     //   cout << ans[i] << ' ';
        s.push(ans[i]);
    }
}

/** @return whether we have a next smallest number */
bool BSTIterator::hasNext() {
    if(s.empty())  return false;
    return true;
}

/** @return the next smallest number */
int BSTIterator::next() {
    int element = s.top();
    s.pop();
    return element;
}

/**
 * Your BSTIterator will be called like this:
 * BSTIterator i = BSTIterator(root);
 * while (i.hasNext()) cout << i.next();
 */
