void Solution::reverseWords(string &A) {
    int si = A.size();
    vector<string> s;
    stringstream ss(A);
    string word;
    while(ss >> word)
        s.push_back(word);
    A = "";
    int vs = s.size();
    for(int i=vs-1;i>=0;i--){
        A += s[i];
        if(i > 0)
            A += " ";
    }
}
