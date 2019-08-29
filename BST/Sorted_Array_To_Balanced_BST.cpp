/**
 * Definition for binary tree
 * struct TreeNode {
 *     int val;
 *     TreeNode *left;
 *     TreeNode *right;
 *     TreeNode(int x) : val(x), left(NULL), right(NULL) {}
 * };
 */
// The answer will always be the median of each of the subarray
// If it contains an even number of element the first mid element can be considered
TreeNode* createTree(const vector<int>& v,int start,int en)
{
    if(start > en)
        return NULL;
    int mid = (start + en) / 2;
    TreeNode* node = new TreeNode(v[mid]);
    
    node -> left = createTree(v,start,mid - 1);
    node -> right = createTree(v,mid + 1,en);
    
    return node;
}
TreeNode* Solution::sortedArrayToBST(const vector<int> &A) {
    int n = A.size();
    if(n == 0)
        return NULL;
    if(n == 1){
        TreeNode* root = new TreeNode(A[0]);
        return root;
    }
    
    TreeNode* root = createTree(A,0,n-1);
    
    return root;
}
