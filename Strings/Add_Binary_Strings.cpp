string Solution::addBinary(string A, string B) {
    int asize = A.size();
    int bsize = B.size();
    if(asize < bsize){
        reverse(A.begin(),A.end());
        for(int i=1;i<=bsize - asize;i++)
            A += "0";
        reverse(A.begin(),A.end());
    }
    else if(bsize < asize){
        reverse(B.begin(),B.end());
        for(int i=1;i<=asize-bsize;i++)
            B += "0";
        reverse(B.begin(),B.end());
    }
    
    reverse(A.begin(),A.end());
    reverse(B.begin(),B.end());
    string ans = "";
    int carry = 0;
    for(int i=0;i<A.size();i++){
        int value = carry + (A[i] - '0') + (B[i] - '0');
        if(value == 0)
            ans += "0";
        else if(value == 1){
            ans += "1";
            if(carry == 1)
                carry = 0;
        }
        else if(value == 2){
            ans += "0";
            carry = 1;
        }
        else if(value == 3){
            ans += "1";
            carry = 1;
        }
    }
    if(carry == 1)
        ans += "1";
    reverse(ans.begin(),ans.end());
    return ans;
}