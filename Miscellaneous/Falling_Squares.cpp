typedef long long ll;
ll md;
bool intersect(pair<ll,ll> a, pair<ll,ll> b)
{
    if(b.second <= a.first || b.first >= a.second)
        return false;
    
    return true;
}
vector<int> Solution::solve(vector<vector<int> > &A) {
    int rows = A.size();
    int col = 2;
    md = 0;
    vector<int> ans;
    if(rows == 0)
        return ans;
    
    if(rows == 1){
        ans.push_back(A[0][1]);
        return ans;
    }
    
    vector<pair<ll,ll> > x(rows),y(rows);
    x[0] = {A[0][0], A[0][0] + A[0][1]};
    y[0] = {0, A[0][1]};
    
    ans.push_back(A[0][1]);
    md = A[0][1];
    for(int i=1;i<rows;i++){
        x[i] = {A[i][0], A[i][0] + A[i][1]};
        y[i] = {0, A[i][1]};
        bool flag = true;
        for(int j=0;j<i;j++){
            if(!intersect(x[i],x[j])){
                if(y[i].second > md)
                    md = y[i].second;
                continue;
            }
            if(y[j].second + A[i][1] > y[i].second)
                y[i] = {y[j].second, y[j].second + A[i][1]};
            if(y[j].second + A[i][1] > md){
                md = y[j].second + A[i][1];
            }
        }
        ans.push_back(md);
    }
    
    return ans;
    
}
