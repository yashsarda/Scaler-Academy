/*
Given two array A and B both of size N consisting of distinct integers. You have to make array A equal to B.
In one move, you can:
choose any element of the array A and change its value to any integer.
do the cyclic right rotation of the array A.

Find the minimum number of moves required to make array A equal to B.

*/

int Solution::solve(vector<int> &A, vector<int> &B) {
    int n = A.size();
    unordered_map<int,int> a, rotation;
    for(int i = 0; i < n; i++) {
        a[A[i]] = i;
    }
    for(int i = 0; i < n; i++) {
        if(a.find(B[i]) != a.end()) {
            int aindex = a[B[i]];
            int bindex = i;
             
            if(aindex < bindex) 
                rotation[bindex - aindex]++;
            else if(aindex > bindex)
                rotation[n - aindex + bindex]++;
            else
                rotation[0]++;
        }
    }
    int answer = n;
    for(int i = 0; i <= n - 1; i++) {
        if(rotation.find(i) != rotation.end()) {
            answer = min(answer, i + n - rotation[i]);
        }
    }
    return answer;
     
}
