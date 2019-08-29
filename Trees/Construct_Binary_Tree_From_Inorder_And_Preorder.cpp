/**
 * Definition for binary tree
 * struct TreeNode {
 *     int val;
 *     TreeNode *left;
 *     TreeNode *right;
 *     TreeNode(int x) : val(x), left(NULL), right(NULL) {}
 * };
 */
TreeNode* buildit(int ins,int ine,int pres,int pree,unordered_map<int,int>& m,vector<int>& inorder,vector<int>& preorder)
{
    if(ins > ine)
        return NULL;
    int index = m[preorder[pres]];
    TreeNode* root = new TreeNode(inorder[index]);
    // If there is only one node then return that node
    if(ins == ine)
        return root;
    // 8 variables
    // left subtree inorder starts at current inorder start and end at value index - 1
    int leftis = ins;
    int leftie = index - 1;
    // Left subtree preorder starts at current preorder start + 1 and ends at 
    // Number of nodes in left subtree is [ins.....index - 1] = index - 1 - ins + 1 = index - ins
    // The end of preorder traversal of left subtree will be pres + number of nodes in left subtree
    int leftps = pres + 1;
    int leftpe = pres + index - ins;
    int rightis = index + 1;
    int rightie = ine;
    int rightps = leftpe + 1;
    int rightpe = pree;
    
    root -> left = buildit(leftis,leftie,leftps,leftpe,m,inorder,preorder);
    root -> right = buildit(rightis,rightie,rightps,rightpe,m,inorder,preorder);
    
    return root;
}
TreeNode* Solution::buildTree(vector<int> &A, vector<int> &B) {
    unordered_map<int,int> m;
    int n = B.size();
    if(n == 0)
        return NULL;
    for(int i=0;i<n;i++)
        m[B[i]] = i;
    TreeNode* root = buildit(0,n - 1,0,n - 1,m,B,A);
    return root;
}
