unsigned int Solution::reverse(unsigned int A) {
    // Do not write main() function.
    // Do not read input, instead use the arguments to the function.
    // Do not print the output, instead return values as specified
    // Still have a doubt. Checkout www.interviewbit.com/pages/sample_codes/ for more details
    unsigned int ans = 0;
    for(int i=0;i<32;i++){
        if(A & (1 << i))
            ans = ans | (1 << (31 - i));
    }
    return ans;
}