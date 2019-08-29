/**
 * Definition for binary tree
 * struct TreeNode {
 *     int val;
 *     TreeNode *left;
 *     TreeNode *right;
 *     TreeNode(int x) : val(x), left(NULL), right(NULL) {}
 * };
 */
// Level order traversal twice and storing the levels
// If the level is even then just reversing the array of nodes at that level
vector<vector<int> > Solution::zigzagLevelOrder(TreeNode* A) {
    vector<vector<int> > ans;
    if(A == NULL)
        return ans;
   /* queue<pair<TreeNode*,int> > q;
    queue<pair<TreeNode*,int> > q2;
    int level = 1;
    q.push({A,level});
    while(!q.empty()){
        pair<TreeNode*,int> t = q.front();
        q.pop();
        q2.push(t);
        if(t.first -> left != NULL)
            q.push({t.first -> left,t.second + 1});
        if(t.first -> right != NULL)
            q.push({t.first -> right,t.second + 1});
    }
    level = 1;
    while(!q2.empty()){
        pair<TreeNode*,int> t = q2.front();
        vector<int> temp;
        while(!q2.empty() && t.second == level){
            temp.push_back(t.first -> val);
            q2.pop();
            t = q2.front();
        }
        if(level % 2 == 0)
            reverse(temp.begin(),temp.end());
        ans.push_back(temp);
        level++;
    }*/
    stack<TreeNode*> st1,st2;
    st1.push(A);
    while(!st1.empty() || !st2.empty()){
        vector<int> temp;
        while(!st1.empty()){
            TreeNode* t = st1.top();
            st1.pop();
            temp.push_back(t -> val);
            if(t -> left != NULL)
                st2.push(t -> left);
            if(t -> right != NULL)
                st2.push(t -> right);
        }
        if(!temp.empty())
            ans.push_back(temp);
        temp.clear();
        while(!st2.empty()){
            TreeNode* t = st2.top();
            st2.pop();
            temp.push_back(t -> val);
            if(t -> right != NULL)
                st1.push(t -> right);
            if(t -> left != NULL)
                st1.push(t -> left);
        }
        if(!temp.empty())
            ans.push_back(temp);
    }
    
    return ans;
}
