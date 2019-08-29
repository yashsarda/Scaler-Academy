// Idea: Just go on splitting the elements and if the last element is even then we can split it into two equal parts to 
// make xor as 0
// Eg: 2 3 5 10 14
// sort the array. Take the cummulative difference
// 0 1 4 6 8
// Since the last element of this array is divisible by 2, hence answer is yes 
string Solution::solve(vector<int> &A) {
    int n = A.size();
    if(n <= 1)
        return "No";
    sort(A.begin(),A.end());
    int start = A[0];
    int diff;
    for(int i=1;i<n;i++){
        diff = A[i] - start;
        start = diff;
    }
    if(start % 2 == 0)
        return "Yes";
    return "No";
}
