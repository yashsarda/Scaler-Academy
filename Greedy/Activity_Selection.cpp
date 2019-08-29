struct t
{
    int st;
    int en;
};
bool comp(struct t const& A,struct t const& B)
{
    if(A.en == B.en)
        return A.st < B.st;
    return A.en < B.en;
}
int Solution::solve(vector<int> &A, vector<int> &B) {
    int asize = A.size();
    int bsize = B.size();
    if(asize == 1)
        return 1;
    vector<t> intervals(asize);
    for(int i=0;i<asize;i++){
        intervals[i].st = A[i];
        intervals[i].en = B[i];
    }
    sort(intervals.begin(),intervals.end(),comp);
    int ans = 1;
    int finish_time = intervals[0].en;
    for(int i=1;i<asize;i++){
        if(intervals[i].st >= finish_time){
            ++ans;
            finish_time = intervals[i].en;
        }
    }
    return ans;
        
}
