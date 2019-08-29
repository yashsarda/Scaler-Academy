int Solution::solve(const string A, const string B) {
    int asize = A.size();
    int bsize = B.size();
    if(bsize < asize)
        return 0;
    int startA = 0;
    int startB = 0;
    while(startA <= asize - 1){
        char c = A[startA];
        if(B[startB] != A[startA])
            return 0;
        if(startB > bsize - 1)
            return 0;
        while(startB <= bsize - 1 && B[startB] == c){
                startB++;
        }
        startA++;
    }
    if(startB <= bsize - 1)
        return 0;
    return 1;
}
