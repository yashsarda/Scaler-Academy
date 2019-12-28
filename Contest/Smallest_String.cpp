string Solution::SmallestString(string A, int B, int C) {
    int n = A.length();
    queue<string> q;
    q.push(A);
    set<string> s;
    s.insert(A);
    while(!q.empty()) {
        string st = q.front();
        q.pop();
        // rotate
        string temp = st.substr(n - B, B) + st.substr(0, n - B);
        if(s.find(temp) == s.end()) {
            q.push(temp);
            s.insert(temp);
        }
        // add
        temp = st;
        for(int i=1;i<n;i+=2) {
            int x = ((st[i] - '0') + C) % 10;
            temp[i] = (x + '0');
        }
        if(s.find(temp) == s.end()) {
            q.push(temp);
            s.insert(temp);
        }
    }
    return *s.begin();
}
