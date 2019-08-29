typedef long long ll;
ll convert_to_decimal(string B)
{
    ll ans = 0;
    ll p = 1;
    reverse(B.begin(),B.end());
    for(int i=0;i<B.size();i++){
        ans = ans + (p * (B[i] - '0'));
        p *= 2;
    }
    return ans;
}
string convert_to_string(string B)
{
    string ans = "";
    for(int i=0;i<B.size();i++){
        if((B[i] - '0') & 1)
            ans += "1";
        else
            ans += "0";
    }
    return ans;
}
vector<int> Solution::solve(vector<char> &A, vector<string> &B) {
    vector<int> ans;
    int n = A.size();
    unordered_map<int,int> m;
    for(int i=0;i<n;i++){
        if(A[i] == '+'){
            string x = convert_to_string(B[i]);
            ll dec = convert_to_decimal(x);
            m[dec]++;
        }
        else if(A[i] == '-'){
            string x = convert_to_string(B[i]);
            ll dec = convert_to_decimal(x);
            m[dec]--;
        }
        else{
            ll dec = convert_to_decimal(B[i]);
            if(m.find(dec) == m.end())
                ans.push_back(0);
            else
                ans.push_back(m[dec]);
        }
    }
    return ans;
}
