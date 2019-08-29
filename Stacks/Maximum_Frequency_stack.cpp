vector<int> Solution::solve(vector<vector<int> > &A) {
    int row = A.size();
    int col = 2;
    unordered_map<int,int> freq;
    stack<pair<int,int> > s1,s2;
    
    vector<int> ans;
    
    for(int i=0;i<row;i++){
        int op = A[i][0];
        int value = A[i][1];
        
        if(op == 1){
            freq[value]++;
            if(s1.empty()){
                s1.push({value,freq[value]});
            }
            else{
                pair<int,int> t = s1.top();
                while(!s1.empty() && t.second > freq[value]){
                    s2.push(t);
                    s1.pop();
                    t = s1.top();
                }
                s1.push({value,freq[value]});
                while(!s2.empty()){
                    pair<int,int> t = s2.top();
                    s2.pop();
                    s1.push(t);
                }
            }
            ans.push_back(-1);
        }
        else{
            pair<int,int> t = s1.top();
            s1.pop();
            freq[t.first]--;
            ans.push_back(t.first);
        }
    }
    return ans;
}
