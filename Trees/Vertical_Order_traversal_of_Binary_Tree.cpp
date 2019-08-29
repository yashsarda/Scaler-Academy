/**
 * Definition for binary tree
 * struct TreeNode {
 *     int val;
 *     TreeNode *left;
 *     TreeNode *right;
 *     TreeNode(int x) : val(x), left(NULL), right(NULL) {}
 * };
 */
vector<vector<int> > Solution::verticalOrderTraversal(TreeNode* A) {
    vector<vector<int> > ans;
    if(A == NULL)
        return ans;
    map<int,vector<int> > m;
    queue<pair<TreeNode*,int> > q;
    q.push({A,0});
    while(!q.empty()){
        pair<TreeNode*,int> p = q.front();
        q.pop();
        m[p.second].push_back(p.first -> val);
        if(p.first -> left != NULL)
            q.push({p.first -> left,p.second - 1});
        if(p.first -> right != NULL)
            q.push({p.first -> right, p.second + 1});
    }
    for(auto it=m.begin();it!=m.end();it++)
        ans.push_back(it->second);
    return ans;
}
