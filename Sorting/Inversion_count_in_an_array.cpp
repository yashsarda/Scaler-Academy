typedef long long ll;
const int mod = 1e9 + 7;
void Merge(vector<int>& A,int start,int mid,int en,ll& ans)
{
    int p = start;
    int q = mid + 1;
    int total = en - start + 1;
    vector<int> aux(total + 5);
    int k = 0;
    for(int i=start;i<=en;i++){
        if(p > mid)
            aux[k++] = A[q++];
        else if(q > en)
            aux[k++] = A[p++];
        else if(A[p] <= A[q])                       // Make sure this <= and not <
            aux[k++] = A[p++];
        else {
            ans = (ans + (mid - p + 1)) % mod;
            aux[k++] = A[q++];
        }
    }
    // Merge in sorted order
    for(int i=0;i<k;i++){
        A[start++] = aux[i];
    }
}
void MergeSort(vector<int>& A,int start,int en,ll& ans)
{
    if(start < en){
        int mid = (start + en) / 2;
        MergeSort(A,start,mid,ans);
        MergeSort(A,mid+1,en,ans);
        Merge(A,start,mid,en,ans);
    }
}
int Solution::solve(vector<int> &A) {
    int n = A.size();
    ll ans = 0;
    MergeSort(A,0,n-1,ans);
    return ans;
}