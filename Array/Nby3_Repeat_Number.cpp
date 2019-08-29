// you have 3 distinct element from the array, if you remove them from the array, your answer does not change.
int Solution::repeatedNumber(const vector<int> &A) {
    // Do not write main() function.
    // Do not read input, instead use the arguments to the function.
    // Do not print the output, instead return values as specified
    // Still have a doubt. Checkout www.interviewbit.com/pages/sample_codes/ for more details

    int n = A.size();
    if(n == 1)
        return A[0];
    int cnt1 = 0;
    int cnt2 = 0;
    int element1,element2;

    for(int i=0;i<n;i++){
        if(A[i] == element1)
            cnt1++;
        else if(A[i] == element2)
            cnt2++;
        else if(cnt1 == 0){
            element1 = A[i];
            cnt1++;
        }
        else if(cnt2 == 0){
            element2 = A[i];
            cnt2++;
        }
        else{
            cnt1--;
            cnt2--;
        }
    }
    cnt1 = 0;
    cnt2 = 0;
    for(int i=0;i<n;i++){
        if(A[i] == element1)
            cnt1++;
        else if(A[i] == element2)
            cnt2++;
    }

    if(cnt1 > (n / 3))
        return element1;

    if(cnt2 > (n / 3))
        return element2;

    return -1;

}
