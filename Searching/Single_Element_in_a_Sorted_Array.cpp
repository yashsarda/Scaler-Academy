int Solution::solve(vector<int> &A) {
    int n = A.size();
    
    int l = 0;
    int h = n - 1;
    
    while(l <= h){
        int mid = l + (h - l) / 2;
        int occurence1 = A[mid];
        int occurence2;
        if(mid == n - 1){
            occurence2 = A[mid - 1];
        }
        else
            occurence2 = A[mid + 1];
        if(occurence1 != occurence2){
            if(mid % 2 == 0)
                h = mid - 1;
            else
                l = mid + 1;
        }
        else{
            if(mid % 2 == 0)
                l = mid + 1;
            else
                h = mid - 1;
        }
     //  cout << occurence1 << ' ' << occurence2 << '\n';
     //   cout << l << ' ' << h << '\n';
    }
    return A[l];
    
}
