//Changed the linear search to binary search
bool check(vector<string>& A,int k)
{
    int s = A.size();
    for(int j=0;j<k;j++){
        char match_with = A[0][j];
        for(int i=1;i<s;i++){
            if(A[i][j] != match_with)
                return false;
        }
    }
    return true;
}
string Solution::longestCommonPrefix(vector<string> &A) {
    int s = A.size();
    int minSize = INT_MAX;
    for(int i=0;i<s;i++)
        minSize = min(minSize,(int)A[i].size());
    int flag = 0;
    int lb = 0;
    int ub = minSize;
    int ans = 0;
    while(lb <= ub){
        int mid = lb + (ub - lb) / 2;
        if(check(A,mid)){
            ans = mid;
            lb = mid + 1;
        }
        else{
            ub = mid - 1;
        }
        
    }
    if(ans == 0)
        return "";
    string a = "";
    for(int i=0;i<ans;i++)
        a += A[0][i];
    return a;
}
