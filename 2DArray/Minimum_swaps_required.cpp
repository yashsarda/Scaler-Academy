// Solution approach
// All the elements which are less than or equal to B will form one subarray in the final answer
// i.e subarray size will be the number of elements less than or equal to B
// So we try all the possible start points and check how many swaps we will require
// The number of swaps in any subarray that we will need will be equal to number of elements greater than B
// We can find that using prefix sums
int Solution::solve(vector<int> &A, int B) {
    int n = A.size();
    vector<int> pref(n+1,0);
    if(A[0] > B)
        pref[1] = 1;
    else
        pref[1] = 0;
    for(int i=1;i<n;i++){
        if(A[i] > B)
            pref[i + 1] = pref[i] + 1;
        else
            pref[i + 1] = pref[i];
    }
    int nlb = 0;
    for(int i=0;i<n;i++){
        if(A[i] <= B)
            nlb++;
    }
    int ans = INT_MAX;
    for(int i=1;i+nlb-1<=n;i++){
        int start = i;
        int end = i+nlb-1;
        int sum = pref[end] - pref[start-1];
        ans = min(ans,sum);
    }
    return ans;

}
