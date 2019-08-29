int Solution::evalRPN(vector<string> &A) {
    stack<int> s;
    int n = A.size();
    if(n == 1)
        return stoi(A[0]);
    int ans = 0;
    for(int i=0;i<n;i++){
        if(A[i] == "+" || A[i] == "-" || A[i] == "*" || A[i] == "/" ){
            int second = s.top();
            s.pop();
            int first = s.top();
            s.pop();
            int result = 0;
            if(A[i] == "+")
                result += first + second;
            else if(A[i] == "-")
                result += first - second;
            else if(A[i] == "*")
                result += first * second;
            else
                result += first / second;
            s.push(result);
            ans = result;
            
        }
        else{
            int x = stoi(A[i]);
            s.push(x);
        }
    }
    return ans;
}
