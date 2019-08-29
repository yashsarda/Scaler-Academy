int Solution::solve(vector<int> &A) {
    int n = A.size();
    if(n == 1)
        return 0;
    
    int ans = 0;
    // mask is useful in reprsenting those number which have bit set 
    int mask = 0;
    int temp = 0;
    for(int i=31;i>=0;i--){
        //set the 2^i bit
        mask = mask | (1 << i);
        // we see if we can form this number or not
        temp = ans | (1 << i);
        
        set<int> s;
        // This will insert all the elements which have bit 1 from position 31 to i
        for(int num:A){
            s.insert(num & mask);
        }
        
        for(auto it=s.begin();it!=s.end();it++){
            // We try to see if we can form this temp. 
            // How ? We know that a ^ b = c, then a ^ c = b;
            // a ^ b = temp then a ^ temp = b;
            // For every a present in the set we try to find b
            // if we don't find any we cannot form the result so we don't update ans
            if(s.find(*it ^ temp) != s.end()){
                ans = temp;
                break;
            }
        }
    }
    return ans;
}
