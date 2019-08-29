// This utility function calculate the number of elements strictly smaller than target
int number_less(vector<vector<int> >& A,int target,int row)
{
  //  cout << "In number less\n";
  //  cout << target - 1 << '\n';
    int ans = 0;
    for(int i=0;i<row;i++){
        // This finds the first position in the array with number greater than equal to target
        int no = lower_bound(A[i].begin(),A[i].end(),target) - A[i].begin();
      //  cout << no << '\n';
        ans += no;
    }
    return ans;
}
// This utility function calculates the number of elements strictly greater than target
int number_greater(vector<vector<int> >& A,int target,int row)
{
  //  cout << "In numbers greater\n";
  //  cout << target + 1 << '\n';
    int ans = 0;
    for(int i=0;i<row;i++){
        // We need to change target to target + 1 since we want strictly greater
        int no = lower_bound(A[i].begin(),A[i].end(),target + 1) - A[i].begin();
      //  cout << no << '\n';
        ans += A[0].size() - no;
    }
    return ans;
}
int Solution::findMedian(vector<vector<int> > &A) {
    int row = A.size();
    int col = A[0].size();
    int median = (row * col) >> 1;
    int mine = INT_MAX, maxe = INT_MIN;
    
    for(int i=0;i<row;i++)
        mine = min(mine,A[i][0]);
    
    for(int i=0;i<row;i++)
        maxe = max(maxe,A[i][col-1]);
    // Finding the lower bounds and the upper bounds
    int lb = mine;
    int ub = maxe;
   // cout << lb << ' ' << ub << '\n';
    int total = row * col;
    while(lb <= ub){
        int mid = lb + ((ub - lb) >> 1);
      //  cout << mid << ' ';
        int x1 = number_less(A,mid,row);
        int x2 = number_greater(A,mid,row);
      // cout << "x1 = " << x1 << ' ' << "x2 = " << x2 << '\n';
      // This case is when the elements is not present in the matrix
        if(x1 + x2 == total){
            if(x1 <= median){
                lb = mid + 1;
            }
            else
                ub = mid - 1;
        }
        else{
            // This case is when the element is present in the matrix
            int l = x1;
            int r = total - x2 - 1;
          //  cout << l << ' ' << r << '\n';
            if(median >= l && median <= r)
                return mid;
            if(r < median)
                lb = mid + 1;
            if(l > median)
                ub = mid - 1;
        }
     }
}
