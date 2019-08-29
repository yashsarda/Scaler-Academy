void Solution::nextPermutation(vector<int> &A) {
    // Do not write main() function.
    // Do not read input, instead use the arguments to the function.
    // Do not print the output, instead return values as specified
    // Still have a doubt. Checkout www.interviewbit.com/pages/sample_codes/ for more details

    int n = A.size();
    if(n == 1)
        return;
    if(n == 2){
        swap(A[0],A[1]);
        return;
    }
    int min_el = *min_element(A.begin(),A.end());
    int right = n - 2;
    for(int i=n-2;i>=0;i--){
        if(A[i] > A[i+1])
            right-=1;
        else
            break;
    }
    if(right == n-2)
        swap(A[n-1],A[n-2]);
    else{
        if(right == -1){
            int next_element = min_el;
            int index = 0;
            for(int j=1;j<n;j++){
                if(A[j] == next_element){
                    index = j;
                    break;
                }
            }
            swap(A[index],A[0]);
            reverse(A.begin(),A.end());
        }
        else{
            int element = A[right];
            int next_element = INT_MAX;
            int index;
            for(int j=right+1;j<n;j++){
                if(A[j] >= element && A[j] <= next_element){
                    index = j;
                    next_element = A[j];
                }
            }
            swap(A[index],A[right]);
            reverse(A.begin()+right+1,A.end());
        }
    }

}
