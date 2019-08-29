bool isPalindrome(string substring)
{
    string rev = substring;
    reverse(rev.begin(),rev.end());
    return rev == substring;
}
string getSubstring(int start,int en,string A)
{
    string ans;
    for(int i=start;i<=en;i++)
        ans += A[i];
    return ans;
}
void palindromePart(int index,string A,vector<vector<string> >& ans,vector<string>& inter)
{
    if(index == A.size()){
        ans.push_back(inter);
        return;
    }
    
    for(int i=index;i<A.size();i++){
        string substring = getSubstring(index,i,A);
      //  cout << substring << '\n';
        if(isPalindrome(substring)){
            inter.push_back(substring);
            palindromePart(i+1,A,ans,inter);
            inter.pop_back();
        }
    }
}
vector<vector<string> > Solution::partition(string A) {
    vector<vector<string> > ans;
    vector<string> inter;
    
    palindromePart(0,A,ans,inter);
    return ans;
}
