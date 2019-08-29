bool isPossible(vector<int>& A,int B,int distance)
{
    int cows = B - 1;
    int cowP[B];
    cowP[0] = 0;
    int previous = 0;
    for(int i=1;i<A.size();i++){
        if(cows == 0)
            return true;
        if(A[i] - A[cowP[previous]] >= distance){
            cows--;
            previous++;
            cowP[previous] = i;
        }
    }
    if(cows == 0)
        return true;
    return false;
}
int Solution::solve(vector<int> &A, int B) {
    int n = A.size();
    sort(A.begin(),A.end());
    int mine = INT_MAX;
    for(int i=1;i<n;i++)
        mine = min(mine,A[i]-A[i-1]);
    int maxe = INT_MIN;
    maxe = A[n-1] - A[0];
    int lb = mine;
    int ub = maxe;
  //  cout << lb << ' ' << ub << '\n';
    int ans = 0;
    while(lb <= ub){
        int mid = lb + ((ub - lb) >> 1);
      //  cout << mid << ' ';
        if(isPossible(A,B,mid)){
            ans = mid;
            lb = mid + 1;
        }
        else
            ub = mid - 1;
      //  cout << lb << ' ' << ub << '\n';
    }
    return ans;
}
