typedef long long ll;
const int N = 13;
ll fact[N];
void getList(int n,int k,vector<int>& v,vector<int>& ans)
{
    if(n == 0){
        return;
    }
    // Here k will be greater than INT_MAX so just the first element of the 
    // remaining vector will be included 
    if(n - 1 >= 13){
        ans.push_back(v[0]);
        v.erase(remove(v.begin(),v.end(),v[0]),v.end());
    } 
    else{
        int x = k / fact[n-1];
        ans.push_back(v[x]);
        v.erase(remove(v.begin(),v.end(),v[x]),v.end());
        k = k % (fact[n - 1]);
    }
    getList(n - 1,k,v,ans);
    return;
}
string convert_to_string(int number)
{
    stringstream ss;
    string s;
    ss << number;
    s = ss.str();
    return s;
}
string Solution::getPermutation(int A, int B) {
    fact[0] = 1;
    for(int i=1;i<13;i++)
        fact[i] = fact[i-1] * i;
    vector<int> v;
    vector<int> ans;
    for(int i=1;i<=A;i++)
        v.push_back(i);
    getList(A,B-1,v,ans);
    string an;
    for(int i=0;i<ans.size();i++){
        an = an + convert_to_string(ans[i]);
    }
    return an;
}
