/**
 * Definition for binary tree
 * struct TreeNode {
 *     int val;
 *     TreeNode *left;
 *     TreeNode *right;
 *     TreeNode(int x) : val(x), left(NULL), right(NULL) {}
 * };
 */
const int mod = 1003;
typedef unsigned long long ll;
ll ans = 0;
inline ll add(ll ans,ll x)
{
    ans = (ans % mod + x % mod) % mod;
    return ans;
}
void sumNumber(TreeNode* root,vector<int>& intermediate)
{
    if(root == NULL)
        return;
    
    if(!root -> left && !root -> right){
        int si = intermediate.size();
        reverse(intermediate.begin(),intermediate.end());
        ll mul= 1;
        ll temp = 0;
        for(int i=0;i<si;i++){
            temp = add(temp,intermediate[i] * mul);
            mul *= 10;
            // Just the wrong answer because the below line was not included
            mul %= mod;
        }
        reverse(intermediate.begin(),intermediate.end());
        ans = add(ans,temp);
        return;
    }
    
    if(root -> left != NULL){
        intermediate.push_back(root -> left -> val);
        sumNumber(root -> left,intermediate);
        intermediate.pop_back();
    }
    if(root -> right !=  NULL){
        intermediate.push_back(root -> right -> val);
        sumNumber(root -> right,intermediate);
        intermediate.pop_back();
    }
}
int Solution::sumNumbers(TreeNode* A) {
    if(A == NULL)
        return 0;
    ans = 0;
    vector<int> intermediate;
    intermediate.push_back(A -> val);
    sumNumber(A,intermediate);
    return ans;
    
}