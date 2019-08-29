bool check(int n)
{
    int s = sqrt(n);
    return s * s == n;
}
void numberOfSquare(int index,vector<int>& A,int& ans)
{
    if(index == A.size() - 1){
        if(check(A[index] + A[index - 1]))
            ++ans;
        return;
    }
    
    unordered_map<int,int> m;
    for(int i=index;i<A.size();i++){
        m[A[i]] = 1;
    }
    
    for(int i=index;i<A.size();i++){
        if(m[A[i]] == 1){
            m[A[i]] = 0;
            swap(A[index],A[i]);
            if(index == 0)
                numberOfSquare(index + 1,A,ans);
            if(index > 0 && check(A[index] + A[index - 1]))
                numberOfSquare(index + 1,A,ans);
            //m[A[i]] = 1;
            swap(A[index],A[i]);
        }
    }
}
int Solution::solve(vector<int> &A) {
    int ans = 0;
    numberOfSquare(0,A,ans);
    
    return ans;
}
