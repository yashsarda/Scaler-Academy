int convert_to_int(string s)
{
    int x = 0;
    stringstream ss(s);
    ss >> x;
    return x;
}
string Solution::solve(string A, int B) {
    int len = 0;
    int a = A.size();
    stack<pair<char,int> > st;
    for(int i=0;i<a;){
        if(len >= B)
            break;
        if(A[i] >= 'a' && A[i] <= 'z'){
            len++;
            st.push({A[i],len});
            i++;
        }
        else{
            string x = "";
            int j = i;
            while(j < a && (A[j] >= '0' && A[j] <= '9')){
                x += A[j];
                j++;
            }
            i = j;
         //   cout << x << '\n';
            int y = convert_to_int(x);
            len = len * y;
        }
    }
    string ans = "";
    while(!st.empty()){
        pair<char,int> x = st.top();
        st.pop();
        int mod = B % x.second;
        if(mod == 0){
            ans += x.first;
            return ans;
        }
        B = mod;
    }
    
}
