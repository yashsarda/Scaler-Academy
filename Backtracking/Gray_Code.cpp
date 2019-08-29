// Awesome AC in one go
vector<string> gray(int A)
{
    // Base case
    if(A == 1){
        vector<string> aux;
        aux.push_back("0");
        aux.push_back("1");
        return aux;
    }
    
    // Hypothesis
    vector<string> subproblem = gray(A - 1);
    
    
    // Induction
    vector<string> sol;
    int s = subproblem.size();
    
    for(int i=0;i<s;i++){
        string a = subproblem[i];
        reverse(a.begin(),a.end());
        a = a + "0";
        reverse(a.begin(),a.end());
        sol.push_back(a);
    }
    
    for(int i=s - 1;i>=0;i--){
        string a = subproblem[i];
        reverse(a.begin(),a.end());
        a = a + "1";
        reverse(a.begin(),a.end());
        sol.push_back(a);
    }
    
    return sol;
}
int convert_to_dec(string a)
{
    reverse(a.begin(),a.end());
    int p = 1;
    int sum = 0;
    for(int i=0;i<a.size();i++){
        sum = sum + (a[i] - '0') * p;
        p *= 2; 
    }
    return sum;
}
vector<int> Solution::grayCode(int A) {
    // Instead of returning the ans in int return in binary format and then convert to decimal
    vector<string> v = gray(A);
    vector<int> ans(v.size());
    
    for(int i=0;i<v.size();i++)
        ans[i] = convert_to_dec(v[i]);
    
    return ans;
}
