int convert_to_int(string s)
{
    stringstream ss(s);
    int x = 0;
    ss >> x;
    return x;
}
int Solution::solve(string A) {
    
    // Remove leading zeros if there are any
    reverse(A.begin(),A.end());
    while(A.back() == '0')
        A.pop_back();
    reverse(A.begin(),A.end());
    int len = A.size();
    if(len == 1){
        if(A[0] == '8')
            return 1;
        return 0;
    }
    else if(len == 2){
        int i = convert_to_int(A);
        if(i % 8 == 0)
            return 1;
        return 0;
    }
    else{
       string t = "";
       t += A[len - 3];
       t += A[len - 2];
       t += A[len - 1];
       int i = convert_to_int(t);
       if(i % 8 == 0)
            return 1;
        return 0;
    }
}
