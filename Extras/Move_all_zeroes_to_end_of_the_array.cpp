vector<int> Solution::solve(vector<int> &A) {
    int size = A.size();
    if(size <= 1)
        return A;

    int count_zero = 0;
    int count_non_zero = 0;
    for(int i=0;i<size;i++){
        if(A[i] == 0)
            count_zero++;
        else
            count_non_zero++;
    }
    if(count_zero == 0 && count_non_zero != 0 || count_zero != 0 && count_non_zero == 0)
        return A;

    int i = 0;
    int j = 0;

    while(A[j] != 0)
        j++;
    i = j;

    while(A[i] == 0)
        i++;

    while(i < size && j < size){
        swap(A[i],A[j]);
        while(j < size && A[j] != 0)
            j++;
        while(i < size && A[i] == 0)
            i++;
    }

    return A;
}
