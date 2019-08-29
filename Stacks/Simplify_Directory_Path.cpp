// It's not necessary that the path ends with /
// eg /a/./b -> /a/b
// Push the directories in the stack. If we have .. then we pop from the stack
// Also don't push if the directory is .
// If the end point is not / then look at the last directory, and perform the same action
string Solution::simplifyPath(string A) {
    int start = 1;
    int found = A.find("/",start);
    stack<string> s;
    while(found != string::npos){
        string to = A.substr(start,found - start);
        if(to == ".."){
            if(!s.empty())
                s.pop();
        }
        else if(to != "."){
            if(to.length() >= 1){
                reverse(to.begin(),to.end());
                to += "/";
                reverse(to.begin(),to.end());
                s.push(to);
            }
        }
        start = found + 1;
        found = A.find("/",start);
    }
    if(start != A.length()){
        int x = A.length();
        string to = A.substr(start,x - start);
        if(to == ".."){
            if(!s.empty())
            s.pop();
        }
        else if(to != "."){
            // The condition is required for //a/b
            if(to.length() >= 1){
                reverse(to.begin(),to.end());
                to += "/";
                reverse(to.begin(),to.end());
                s.push(to);
            }
        }
    }
    vector<string> v;
    while(!s.empty()){
        string x = s.top();
        v.push_back(x);
        s.pop();
    }
    string ans = "";
    for(int i=v.size() - 1;i>=0;i--)
        ans += v[i];
    if(ans == "")
        return "/";
    return ans;
}
