// Just missed the = in <= and it costed me a lot of time 
typedef long long ll;
void Merge(vector<int>& A,int start,int mid,int en,ll& ans)
{
   // cout << "start = " << start << " mid = " << mid << " en = " << en << '\n';
    int total = en - start + 1;
    vector<int> aux(total + 5);
    int k = start;
    ll cnt = 0;
    for(int j=mid+1;j<=en;j++){
        while(k <= mid && ((ll)A[k] <= (2ll * A[j])))
            k++;
      //  cout << "j = " << j << ' '  << A[j] << " k = " << k << ' ' << A[k] << '\n';
        cnt += mid - k + 1;
    }
  //  cout << "cnt = " << cnt << '\n';
    ans += cnt;
    int p = start;
    int q = mid + 1;
    k = 0;
    for(int i=start;i<=en;i++){
        if(p > mid)
            aux[k++] = A[q++];
        else if(q > en)
            aux[k++] = A[p++];
        else if(A[p] < A[q])
            aux[k++] = A[p++];
        else
            aux[k++] = A[q++];
    }
    for(int i=0;i<k;i++)
        A[start++] = aux[i];
    
}
void MergeSort(vector<int>& A,int start,int en,ll& ans)
{
    if(start == en)
        return;
    int mid = (start + en) / 2;
    MergeSort(A,start,mid,ans);
    MergeSort(A,mid + 1,en,ans);
    Merge(A,start,mid,en,ans);
}
int Solution::solve(vector<int> &A) {
    int n = A.size();
    if(n == 1)
        return 0;
    if(n == 2){
        if((ll)A[0] > 2ll * A[1])
            return 1;
        return 0;
    }
    ll ans = 0;
    MergeSort(A,0,n-1,ans);
    return ans;
}
