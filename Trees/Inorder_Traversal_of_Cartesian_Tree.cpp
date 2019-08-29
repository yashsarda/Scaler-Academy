/**
 * Definition for binary tree
 * struct TreeNode {
 *     int val;
 *     TreeNode *left;
 *     TreeNode *right;
 *     TreeNode(int x) : val(x), left(NULL), right(NULL) {}
 * };
 */
unordered_map<int, int> ma;
vector<bool> visited;
int find_max(vector<int>& A, int start,int end)
{
    int mat = INT_MIN;
    for(int i=start;i<end;i++){
        if(!visited[i]){
            if(A[i] > mat){
                mat = A[i];
            }
        }
    }
    if(mat == INT_MIN)
        return mat;
    
    for(int i=start;i<end;i++){
        if(A[i] == mat)
            visited[i] = true;
    }
    
    return mat;
}
TreeNode* construct(vector<int>& A, int start,int end)
{
    if(start >= end)
        return NULL;
    
    int answer = find_max(A,start,end);
    if(answer == INT_MIN)
        return NULL;
    int index = ma[answer];
    
    TreeNode* root = new TreeNode(answer);
    root -> left = construct(A,start, index);
    root -> right = construct(A, index + 1, end);
    
    return root;
}
TreeNode* Solution::buildTree(vector<int> &A) {
    int n = A.size();
    if(n == 0)
        return nullptr;
    ma.clear();
    visited.clear();
    visited.resize(n,false);
    TreeNode* root = NULL;
    if(n == 1){
        root = new TreeNode(A[0]);
        return root;
    }
    
    for(int i=0;i<n;i++)
        ma[A[i]] = i;
    root = construct(A,0,n);
    
    return root;
}
