// New value = index
// Old value is A[index]
// How to encode two numbers in one, use number = quotient * divisor + remainder;
// now we can encode the numbers in quotient and remainder so the divisor should be common
// what will it be:- the size of the array
vector<int> Solution::solve(vector<int> &A) {
    int n = A.size();
    for(int i=0;i<n;i++){
        A[A[i] % n] += i * n;
    }
    for(int i=0;i<n;i++)
        A[i] = A[i] / n;
    return A;
}
