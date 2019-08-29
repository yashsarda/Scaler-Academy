string Solution::solve(string A, int B) {
    int si = A.size();
    if(si == 0)
        return "";
    
    B = B % 26;
    
    vector<int> freq(26,0);
    
    for(int i=0;i<si;i++)
        freq[A[i] - 'a']++;
    
    string ans = "";
    for(int i=0;i<si;i++){
        if(freq[A[i] - 'a'] % 2 == 0){
            char c = 'a' + (A[i] - 'a' + B) % 26;
            ans += c;
        }
        else {
            char c = 'a' + (A[i] - 'a' - B + 26) % 26;
            ans += c;
        }
    }
    return ans;
}
