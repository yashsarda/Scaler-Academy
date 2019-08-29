struct triplet
{
    int i,j;
    int value;
};
struct comp
{
    bool operator()(triplet const& A,triplet const& B)
    {
        return A.value < B.value;
    }
};
vector<int> Solution::solve(vector<int> &A, vector<int> &B) {
    int asize = A.size();
    int bsize = B.size();
    vector<int> ans;
    if(asize == 1){
        ans.push_back(A[0] + B[0]);
        return ans;
    }
    sort(A.begin(),A.end());
    sort(B.begin(),B.end());
    priority_queue<triplet,vector<triplet>,comp > pq;
    map<pair<int,int>,bool > m;
    triplet temp;
    temp.i = asize - 1;
    temp.j = bsize - 1;
    temp.value = A[asize - 1] + B[bsize - 1];
    pq.push(temp);
    m[{temp.i,temp.j}] = true;
    
    for(int k=0;k<asize;k++){
        triplet t = pq.top();
        pq.pop();
        ans.push_back(t.value);
        if(t.j - 1 >= 0 && m.find({t.i,(t.j-1)}) == m.end()){
            triplet x;
            x.i = t.i;
            x.j = t.j - 1;
            x.value = A[x.i] + B[x.j];
            pq.push(x);
            m[{t.i,t.j-1}] = true;
        }
        if(t.i - 1 >= 0 && m.find({(t.i-1),t.j}) == m.end()){
            triplet x;
            x.i = t.i - 1;
            x.j = t.j;
            x.value = A[x.i] + B[x.j];
            pq.push(x);
            m[{t.i-1,t.j}] = true;
        }
    }
    return ans;
    
}
