/*
Given an integer array A of size N. In one operation, you can remove any element from the array and cost of this operation is 
sum of all elements in the array present before this operation. 
Find the minimum cost to remove all elements from the array. NOTE: Return the answer modulo 109 + 7 as the answer can be large

*/

int Solution::solve(vector<int> &A) {
    int n = A.size();
    sort(A.begin(), A.end());
    
    const int mod = 1e9  +7;
    long long answer = 0;
    
    long long sum = 0;
    for(int element : A)
        sum += element;
    
    while(A.size() > 0) {
        int last_element = A.back();
        A.pop_back();
        answer = (answer + sum) % mod;
        sum -= last_element;
    }
    
    return answer;
}
