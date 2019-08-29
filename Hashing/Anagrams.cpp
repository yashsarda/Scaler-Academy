// Just store the first occurence of string with its index in hashmap
// Then again iterate over the array and find the frequency of string 
// if the frequency is already present in the earlier map just take it's index and push the index of this
// string in the new map
vector<vector<int> > Solution::anagrams(const vector<string> &A) {
    int n = A.size();
    map<vector<int>,int> m;
    for(int i=0;i<n;i++){
        vector<int> freq(26,0);
        for(int j=0;j<A[i].size();j++)
            freq[A[i][j] - 'a']++;
        if(m.find(freq) == m.end())
            m[freq] = i;
    }
    map<int,vector<int> > m2;
    for(int i=0;i<n;i++){
        vector<int> freq(26,0);
        for(int j=0;j<A[i].size();j++){
            freq[A[i][j] - 'a']++;
        }
        if(m.find(freq) != m.end())
            m2[m[freq]].push_back(i+1);
    }
    vector<vector<int> > sol;
    for(auto it=m2.begin();it!=m2.end();it++){
        vector<int> temp = it->second;
        sol.push_back(temp);
    }
    return sol;
}
