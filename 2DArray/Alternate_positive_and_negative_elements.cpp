vector<int> Solution::solve(vector<int> &A) {
    int n = A.size();
    if(n == 1)
        return A;
    else if(n == 2){
        if(A[0] > A[1])
            swap(A[0],A[1]);
        return A;
    }
    else{
        int number_of_negative = 0;
        int number_of_positive = 0;
        for(int i=0;i<n;i++){
            if(A[i] < 0)
                number_of_negative++;
            else
                number_of_positive++;
        }
        int n_i = min(number_of_negative,number_of_positive);
        int nd = n_i * 2;
        int temp_storage = 0;
        for(int i=0;i<nd;i+=2){
            if(A[i] < 0 && A[i+1] >= 0)
                continue;
            if(A[i] < 0){
                if(A[i+1] < 0){
                    int index = 0;
                    for(int j=i+1;j<n;j++){
                        if(A[j] >= 0){
                            index = j;
                            break;
                        }
                    }
                    temp_storage = A[index];
                    for(int k=index-1;k>i;k--)
                        A[k+1] = A[k];
                    A[i+1] = temp_storage;
                }
            }
            else{
                int index = 0;
                for(int j=i+1;j<n;j++){
                    if(A[j] < 0){
                        index = j;
                        break;
                    }
                }
                temp_storage = A[index];
                    for(int k=index-1;k>=i;k--)
                        A[k+1] = A[k];
                A[i] = temp_storage;
            }
        }
    }
    return A;
}
