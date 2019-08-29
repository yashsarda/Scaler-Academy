bool isPalindrome(string s,int start,int en)
{
    string t = "";
    for(int i=start;i<=en;i++)
        t += s[i];
    string p = t;
    reverse(p.begin(),p.end());
    return p == t;
}
vector<vector<int> > Solution::solve(vector<string> &A) {
    int n = A.size();
    map<string,int> m;
    for(int i=0;i<n;i++){
        string temp = A[i];
        reverse(temp.begin(),temp.end());
        m[temp] = i;
    }
    vector<vector<int> > ans;
    for(int i=0;i<n;i++){
        vector<int> temp;
        if(m.find("") != m.end()){
            int index = m[""];
            if(index != i && isPalindrome(A[i],1,A[i].size() - 1)){
                temp.push_back(i);
                temp.push_back(index);
                if(find(ans.begin(),ans.end(),temp) == ans.end())
                    ans.push_back(temp);
            }
        }
        for(int j=0;j<A[i].size();j++){
            string x = A[i].substr(0,j+1);
            temp.clear();
            if(m.find(x) != m.end()){
                int index = m[x];
                if(index != i && isPalindrome(A[i],j+1,A[i].size()-1)){
                     temp.push_back(i);
                     temp.push_back(index);
                     if(find(ans.begin(),ans.end(),temp) == ans.end())
                        ans.push_back(temp);
                }
            }
            temp.clear();
            x = A[i].substr(j,A[i].size());
            if(m.find(x) != m.end()){
                int index = m[x];
                if(index != i && isPalindrome(A[i],0,j-1)){
                    temp.push_back(index);
                    temp.push_back(i);
                    if(find(ans.begin(),ans.end(),temp) == ans.end())
                        ans.push_back(temp);
                }
            }
        }
    }
    return ans;
}
