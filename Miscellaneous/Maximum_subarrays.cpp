#define pb push_back
const int mod = 1e9 + 7;
vector<int> Solution::solve(vector<int> &A) {
    int asize = A.size();
    vector<int> B;
    if(asize == 0)
        return B;
    if(asize == 1){
        B.pb(1);
        return B;
    }
    
    stack<int> s;
    vector<int> left(asize), rig(asize);
    
    // find the next greater element on the right side for every element
    for(int i=0;i<asize;i++){
        int element = A[i];
        if(s.empty())
            s.push(i);
        else{
            int t = s.top();
            int el = A[t];
            while(!s.empty() && el < element){
                rig[t] = i;
                s.pop();
                if(s.empty())
                    break;
                t = s.top();
                el = A[t];
            }
        }
        s.push(i);
    }
    while(!s.empty()){
        int t = s.top();
        rig[t] = 0;
        s.pop();
    }
    // find the next greater element on the left side for every element
    for(int i=asize-1;i>=0;i--){
        int element = A[i];
        if(s.empty())
            s.push(i);
        else{
            int t = s.top();
            int el = A[t];
            while(!s.empty() && el < element){
                left[t] = i;
                s.pop();
                if(s.empty())
                    break;
                t = s.top();
                el = A[t];
            }
        }
        s.push(i);
    }
    while(!s.empty()){
        int t = s.top();
        left[t] = -1;
        s.pop();
    }
    
    // final answer  = x (number of element less than current element) + y (number of element greater than current element)
    //                  + (x * y)
    for(int i=0;i<asize;i++){
        long long x,y,answer = 0;
        if(left[i] == -1)
            x = i;
        else
            x = i - left[i] - 1;
        
        if(rig[i] == 0)
            y = asize - i - 1;
        else
            y = rig[i] - i - 1;
        
        answer = (answer % mod + x % mod) % mod;
        answer = (answer % mod + y % mod) % mod;
        answer = (answer % mod + (x * 1ll * y) % mod) % mod;
        answer = (answer + 1) % mod;
        B.pb(answer);
    }
    
    return B;
}
