// Idea: The answer is not going to be a number which divides both A and B
// since we require the number B and answer to be co-prime
// So the answer will surely be less than the gcd of A and B (if it is > 1) because the gcd divides both of the number 
// We keep on dividing until we don't get gcd(A,B) = 1
int Solution::cpFact(int A, int B) {
    int ans = 0;
    /*for(int i=1;i*i<=A;i++){
        if(A % i == 0){
            int first = i;
            int second = A / i;
            if(ans >= first)
                continue;
            if(ans >= second)
                continue;
            if(__gcd(B,first) == 1)
                ans = max(ans,first);
            if(__gcd(B,second) == 1)
                ans = max(ans,second);
        }
    }*/
    while(__gcd(A,B) != 1){
        int x = __gcd(A,B);
        A = A / x;
    }
    ans = A;
    return ans;
}
