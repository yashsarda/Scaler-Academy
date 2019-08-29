TreeNode* postin(int ins,int ine,int pos,int poe,unordered_map<int,int>& m,vector<int>& inorder,vector<int>& postorder)
{
    if(ins > ine || pos > poe)
        return NULL;
    int index = m[postorder[poe]];
    TreeNode* root = new TreeNode(inorder[index]);
    if(ins == ine)
        return root;
    
    
    int size_of_left = index - ins;
    int size_of_right = ine - index;
    
    // the inorder indexes are set same in the preorder and postorder
    int lins = ins;
    int line = index - 1;
    int rins = index + 1;
    int rine = ine;
    
    //The right subtree starts will start index as end of the postorder (which is the root) - size of the right subtree 
    int rpos = poe - size_of_right;
    // The end of the right subtree is just 1 less than current root
    int rpoe = poe - 1;
     // The end of left subtree is just 1 index less than start of the right subtree
    int lpoe = rpos - 1;
    // The start of left subtree will start at 1 behind last element of left subtree - size of left subtree
    // int lpos = lpoe - size_of_left + 1;
    int lpos = pos;
   
    
    root -> left = postin(lins,line,lpos,lpoe,m,inorder,postorder);
    root -> right = postin(rins,rine,rpos,rpoe,m,inorder,postorder);
    
    return root;
}

TreeNode* Solution::buildTree(vector<int> &A, vector<int> &B) {
    int n = A.size();
    if(n == 0)
        return NULL;
    unordered_map<int,int> m;
    for(int i=0;i<n;i++)
        m[A[i]] = i;
    
    TreeNode* root = postin(0,n - 1,0,n - 1,m,A,B);
    return root;
}
