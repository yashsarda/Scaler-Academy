bool check(vector<int>& fa,vector<int>& fb)
{
    for(int i=0;i<26;i++){
        if(fa[i] != fb[i])
            return false;
    }
    return true;
}
vector<int> Solution::solve(string A, string B) {
    vector<int> ans;
    int asize = A.size();
    int bsize = B.size();
    vector<int> freq(26);
    // Calculate the frequency of characters in B
    for(int i=0;i<bsize;i++)
        freq[B[i] - 'a']++;
    
    // Find the first occurence of text in A which have the same frequency of characters as in B
    vector<int> freq2(26);
    int i;
    for(i=0;i + bsize <= asize;i++){
        string t = A.substr(i,i + bsize);
        freq2.clear();
        for(int j=0;j<t.size();j++)
            freq2[t[j] - 'a']++;
        if(check(freq2,freq)){
            ans.push_back(i);
            break;
        }
    }
    for(int j=i + bsize;j< asize;j++){
        freq2[A[j] - 'a']++;
        freq2[A[i]- 'a']--;
        if(check(freq2,freq))
            ans.push_back(i + 1);
        i++;
    }
    return ans;
}
