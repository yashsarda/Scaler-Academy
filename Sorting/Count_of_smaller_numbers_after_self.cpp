#define f first
#define s second
void Merge(vector<pair<int,int> >&v,int start,int mid,int en,vector<int>& ans)
{
    int p = start;
    int q = mid + 1;
    
    int total = en - start + 1;
    vector<pair<int,int> > aux(total + 5);
    int counter = 0;                            // counter indicates how many number in the second array are less than in first array
    int k = 0;
    for(int i=start;i<=en;i++){
        if(p > mid){
            aux[k++] = v[q++];
        }
        else if(q > en){
            ans[v[p].s] += counter;
            aux[k++] = v[p++];
        }
        else if(v[p].f <= v[q].f){
            ans[v[p].s] += counter;
            aux[k++] = v[p++];
        }
        else{
            counter++;
            aux[k++] = v[q++];
        }
    }
    for(int i=0;i<k;i++)
        v[start++] = aux[i];
}
void MergeSort(vector<pair<int,int> >&v, int start,int en,vector<int>& ans)
{
    if(start < en){
        int mid = (start + en) / 2;
        MergeSort(v,start,mid,ans);
        MergeSort(v,mid+1,en,ans);
        Merge(v,start,mid,en,ans);
    }
}
vector<int> Solution::solve(vector<int> &A) {
    
    vector<pair<int,int> > v;
    int n = A.size();
    for(int i=0;i<n;i++)
        v.push_back({A[i],i});
    vector<int> ans(n);
    MergeSort(v,0,n-1,ans);
    return ans;
}
