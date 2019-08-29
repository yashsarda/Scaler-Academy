bool palindrome(string s)
{
    string t = s;
    reverse(t.begin(),t.end());
    return t == s;
}
int Solution::solve(string A) {
    int ans = 0;
    int n = A.size();
    for(int i=n;i>0;i--){
        if(palindrome(A.substr(0,i)))
            break;
        else
            ans++;
    }
    return ans;
}
