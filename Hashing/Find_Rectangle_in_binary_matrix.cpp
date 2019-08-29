#define f first
#define s second
int Solution::solve(const vector<vector<int> > &A) {
    int row = A.size();
    int column = A[0].size();
    if(row < 2 || column < 2)
        return 0;
    
    unordered_map<int,vector<int> > r;
    unordered_map<int,vector<int> > c;
    
    for(int i=0;i<row;i++){
        for(int j=0;j<column;j++){
            if(A[i][j] == 1){
                r[i].push_back(j);
                c[j].push_back(i);
            }
        }
    }
    for(int i=0;i<row;i++){
        for(int j=0;j<column;j++){
            if(i == row - 1)
                continue;
            if(j == column - 1)
                continue;
            if(A[i][j] == 1){
                vector<int> x = r[i];
                vector<int> y = c[j];
                int xsize = x.size();
                int ysize = y.size();
                for(int k=0;k<xsize;k++){
                    pair<int,int> z ={-1,-1};
                    if(x[k] > j){
                        z.s = x[k];
                    }
                    if(z.s != -1){
                        for(int l=0;l<ysize;l++){
                            if(y[l] > i){
                                z.f = y[l];
                                if(A[z.f][z.s] == 1)
                                    return 1;
                            }
                        }
                    }
                }
            }
        }
    }
    return 0;
    

}
