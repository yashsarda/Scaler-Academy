/*
Let Fn be n-th Fibonacci number with F1 = 1 and F2 = 1. 
Find count of integer i in the range [A, B] such that the last digit of Fi is prime.
*/

bool isPrime(int element)
{
    return (element == 2 || element == 3 || element == 5 || element == 7);
}
int Solution::solve(int A, int B) {
    
    // After every 60 the cycle repeats
    vector<int> ans;
    ans.push_back(0);
    ans.push_back(1);
    
    for(int i = 1; i <= 58; i++) {
        ans.push_back((ans.back() + ans[ans.size() - 2]) % 10);
    }
    
    vector<int> prime(60, 0);
    prime[0] = 0;
    for(int i = 0; i < 60; i++) {
        prime[i] = prime[i - 1] + isPrime(ans[i]);
    }
    
    int countPrimes = prime.back();
    int totalGroups = (B - A + 1) / 60;
    
    int answer = 0;
    answer += (countPrimes * totalGroups);
    
    if((B - A + 1) % 60 == 0)
        return answer;
    
    A = A + totalGroups * 60;
    A %= 60;
    B %= 60;
    
    if(B < A)
        answer += prime.back() - (A != 0 ? prime[A - 1] : 0) + prime[B];
    else
        answer += prime[B] - (A != 0 ? prime[A - 1] : 0);
    
    return answer;
    
}




