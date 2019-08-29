string Solution::solve(string A) {
    int n = A.size();
    if(n == 1)
        return A;
    
    stack<char> st;
    string ans = "";
    
    st.push(A[0]);
    ans += A[0];
    for(int i=1;i<n;i++){
        if(!st.empty()){
            char x = st.top();
            if(x == A[i]){
                ans.pop_back();
                st.pop();
            }
            else{
                ans += A[i];
                st.push(A[i]);
            }
        }
        else{
            ans += A[i];
            st.push(A[i]);
        }
    }
    if(ans == "")
        return "empty";
    return ans;
}
