/*

Given an array A of integers of size N. For each integer in A, there is a set S of the prime factors of that integer.
 There is a good value associated with each number, which is the sum of XOR of all subsets of set S modulo 109+7.  
 Good Value of the array A 
is the sum of good values associated with each number modulo 109+7. Return Good Value of A.  Note: Set S has no duplicates
*/

/*
Product of first ten primes > 10^9

*/
const int mod = (int) 1e9 + 7;
vector<int> generatePrimeFactors(int element)
{
    vector<int> answer;
    int number = element;
    for(int i = 2; i * i <= number; i++) {
        if(element % i == 0) {
            answer.push_back(i);
            while(element % i == 0) {
                element /= i;
            }
        }
    }
    
    if(element > 1)
        answer.push_back(element);
    
    return answer;
}
int Solution::solve(vector<int> &A) {
    int n = A.size();
    
    int answer = 0;
    for(int i = 0; i < n; i++) {
        vector<int> prime_factors = generatePrimeFactors(A[i]);
        int siz = (int) prime_factors.size();
        int sum = 0;
        for(int k = 0; k < (1 << siz); k++) {
            int xo = 0;
            for(int j = 0; j < 12; j++) {
                if(k & (1 << j)) {
                    xo ^= prime_factors[j];
                }
            }
            sum = (sum + xo) % mod;
        }
        answer = (answer + sum) % mod;
    }
    return answer;
}
