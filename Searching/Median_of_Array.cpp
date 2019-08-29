// Help: Tushar Roy Youtube channel
double Solution::findMedianSortedArrays(const vector<int> &A, const vector<int> &B) {
    
    int n = A.size();
    int m = B.size();
    // We always want the A array to be smaller
    if(n > m){
        double ans = findMedianSortedArrays(B,A);
        return ans;
    }
    // Handling the corner cases
    if(n == 0 && m == 0){
        return 0.0;
    }
    if(n == 0){
        if(m % 2 == 0){
            return (double) (B[m/2] + B[m/2-1]) / 2.0;
        }
        else{
            return (double) B[m/2];
        }
    }
    if(m == 0){
        if(n % 2 == 0){
            return (double) (A[n/2] + A[n/2-1]) / 2.0;
        }
        else{
            return (double) A[n/2];
        }
    }
    // Idea : Basically dividing both array in such a way that the partitions are of equal size
    // i.e the number of elements on left side = number of elements on the right side(in case of odd left contains an extra element) 
    // Every element on the left side must be less than equal to every element on the right side 
    int lb,ub;
    int pX,pY,value1,value2,value3,value4;
    int total = (n + m + 1) / 2;
    lb = 0;
    ub = n ;
    while(lb <= ub){
        int mid = lb + (ub - lb) / 2;
        pX = mid;
        pY = total - mid;
        // pX contains mid elements ans pY contains total - mid elements
       // cout << mid << ' ' << lb << ' ' << ub << '\n';
        if(pX == 0){
            value1 = INT_MIN;
        }
        else{
            value1 = A[pX - 1];
        }
        if(pY == 0){
            value2 = INT_MIN;
        }
        else{
            value2 = B[pY - 1];
        }
        if(pX == n){
            value3 = INT_MAX;
        }
        else{
            value3 = A[pX];
        }
        if(pY == m){
            value4 = INT_MAX;
        }
        else{
            value4 = B[pY];
        }
    //        cout << "Value 1 = " << value1 << ' ' << " Value2 = " << value2;
    //    cout << " Value 3 = " << value3 << ' ' << " Value4 = " << value4;
    //  cout << '\n';
        if(value1 <= value4 && value2 <= value3){
            if((m + n) % 2 == 0){
                int first = max(value1,value2);
                int second = min(value3,value4);
                return (double)(first + second) / 2.0;
            }
            else{
                int ans = max(value1,value2);
                return (double) ans;
            }
        }
        else if(value2 > value3)
            lb = mid + 1;
        else
            ub = mid - 1;
        }
}

 