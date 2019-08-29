// Just find the factors of number N
int findFactors(int number)
{
    int ans = 0;
    for(int i=1;i*i<=number;i++){
        if(number % i == 0){
            if(i == number / i){
                ++ans;
            }
            else
                ans += 2;
        }
    }
    return ans;
}
int Solution::solve(int A) {
    if(A == 1)
        return 0;
    
    int factors = findFactors(A);
    return factors - 1;
}
