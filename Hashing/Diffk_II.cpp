// Why this for so many points. It's the easiest problem in the whole set
int Solution::diffPossible(const vector<int> &A, int B) {
    int n = A.size();
    unordered_map<int,int> m;
    for(int i=0;i<n;i++)
        m[A[i]]++;
    if(B == 0){
        for(int i=0;i<n;i++){
            if(m[A[i]] > 1)
                return 1;
        }
        return 0;
    }
    else{
        for(int i=0;i<n;i++){
            if(m[A[i] - B] > 0)
                return 1;
        }
        return 0;
    }
}
