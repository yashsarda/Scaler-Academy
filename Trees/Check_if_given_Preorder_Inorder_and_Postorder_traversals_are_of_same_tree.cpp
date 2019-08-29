/*struct TreeNode
{
    int val;
    TreeNode* left;
    TreeNode* right;
    
    TreeNode(int val)
    {
        this.val = val;
        left = NULL;
        right = NULL;
    }
}*/
// This method is used to find the first index of the value which is not used 
 int findindex(vector<bool>& used,vector<int>& inorder,int value)
{
    for(int i=0;i<inorder.size();i++){
        if(inorder[i] == value && used[i] == false){
            used[i] = true;
            return i;
        }
    }
    return -1;
}
TreeNode* convert(int ins,int ine,int prs,int pre,vector<bool>& used,vector<int>& inorder,vector<int>& preorder)
{
    if(ins > ine || prs > pre)
        return NULL;
    int index = findindex(used,inorder,preorder[prs]);
    if(index == -1)
        return NULL;
    TreeNode* root = new TreeNode(inorder[index]);
    
    if(ins == ine)
        return root;
    
    int lins = ins;
    int line = index - 1;
    int rins = index + 1;
    int rine = ine;
    
    int lprs = prs + 1;
    int lpre = prs + index - ins;
    int rprs = lpre + 1;
    int rpre = pre;
    root -> left = convert(lins,line,lprs,lpre,used,inorder,preorder);
    root -> right = convert(rins,rine,rprs,rpre,used,inorder,preorder);
    
    return root;
}
void postorder(TreeNode* root,vector<int>& post)
{
    if(root == NULL)
        return;
    postorder(root -> left,post);
    postorder(root -> right,post);
    post.push_back(root -> val);
}
int Solution::solve(vector<int> &A, vector<int> &B, vector<int> &C) {
    int n = A.size();
    if(n == 0)
        return 1;
    vector<bool> used(n,false);
    TreeNode* root = convert(0,n - 1,0,n - 1,used,B,A);
    vector<int> post;
    postorder(root,post);
    for(int i=0;i<n;i++)
        if(post[i] != C[i])
            return 0;
    return 1;
}
