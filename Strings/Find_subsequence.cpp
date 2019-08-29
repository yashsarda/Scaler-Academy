string Solution::solve(string A, string B) {
    int a = A.size();
    int b = B.size();
    if(a > b)
        return "NO";
    
    int i = 0;          // pointer corresponding to A 
    int j = 0;          // pointer corresponding to B
    
    while(i < a && j < b){
        if(A[i] == B[j]){
            i++;
            j++;
        }
        else {
            j++;
        }
    }
    if(i >= a)
        return "YES";
    return "NO";
}
