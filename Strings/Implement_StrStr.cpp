// Is there a more efficient one ?
int Solution::strStr(const string A, const string B) {
    int asize = A.size();
    int bsize = B.size();
    if(bsize == 0 || bsize == 0 && asize == 0)
        return -1;
    int flag;
    for(int i=0;i+bsize-1 < asize;i++){
        flag = 0;
        int k = 0;
        for(int j=i;j<=i+bsize-1;j++){
            if(B[k++] != A[j]){
                flag = 1;
                break;
            }
        }
        if(!flag)
            return i;
    }
    return -1;
}
