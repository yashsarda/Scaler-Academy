vector<int> Solution::prevSmaller(vector<int> &A) {
    
    int n = A.size();
     vector<int> nle(n);
    if(n == 1){
        nle[0] = -1;
        return nle;
    }
    stack<int> s;
    for(int i=n - 1;i>=0;i--){
        int element = A[i];
        if(s.empty())
            s.push(i);
        else{
            int el = A[s.top()];
            while(!s.empty() && el > element){
                int index = s.top();
                nle[index] = element;
                s.pop();
                if(!s.empty())
                    el = A[s.top()];
            }
            s.push(i);
        }
    }
    while(!s.empty()){
        int index = s.top();
        s.pop();
        nle[index] = -1; 
    }
    return nle;
}
