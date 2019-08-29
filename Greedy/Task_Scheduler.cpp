//Scheduling algorithms tricky one
int Solution::solve(string A, int B) {
    int len = A.size();
    if(len == 1)
        return 1;
    int ans = 0;
    priority_queue<int> pq;
    vector<int> cnt(26,0);
    for(int i=0;i<len;i++)
        cnt[A[i] - 'A']++;
    
    for(int i=0;i<26;i++){
        if(cnt[i])
            pq.push(cnt[i]);
    }
    
    while(!pq.empty()){
        int i = 0;
        vector<int> inter;
        while(i <= B){
            if(!pq.empty()){
                int x = pq.top();
                pq.pop();
                if(x - 1)
                    inter.push_back(x - 1);
                ++ans;
            }
            else{
                // The remaining intervals are idle just add them
                if(!inter.empty()){
                    ans += B - i + 1;
                }
                break;
            }
            i++;
        }
        for(int x:inter)
            pq.push(x);
    }
    return ans;
}
