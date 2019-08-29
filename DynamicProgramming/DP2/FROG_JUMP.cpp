map<pair<int,int>,int> m;
map<int, int> u;
bool find_if_possible(vector<int>& A,int index, int prevJump)
{
    if(index >= A.size())
        return 0;
    if(index == A.size() - 1)
        return 1;
    
    if(m.find({index,prevJump}) != m.end())
        return m[{index, prevJump}];
    
    bool result = false;
    
    if(prevJump > 1 && u.find(A[index] + prevJump - 1) != u.end()){
        result |= find_if_possible(A, u[A[index] + prevJump - 1], prevJump - 1);
    }
    
    if(prevJump > 0 && u.find(A[index] + prevJump) != u.end()){
        result |= find_if_possible(A, u[A[index] + prevJump], prevJump);
    }
    
    if(u.find(A[index] + prevJump + 1) != u.end())
        result |= find_if_possible(A, u[A[index] + prevJump + 1], prevJump + 1);

    m[{index, prevJump}] = result;
    
    return result;
}
int Solution::solve(vector<int> &A) {
    int n = A.size();
    // Corner cases 
    if(n == 1){
        return 1;
    }
    m.clear();
    u.clear();
    // dp[idx][prevJump] =  answer for whether frog reaches index idx with prevJump, can it reach the end index
    for(int i=0;i<n;i++){
        u[A[i]] = i;
    }
    bool ans = false;
    ans = find_if_possible(A,0,0);
    
    return ans;
}
