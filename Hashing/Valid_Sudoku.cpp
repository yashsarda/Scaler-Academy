int Solution::isValidSudoku(const vector<string> &A) {
    int n = A.size();
    map<int,bool> isPresent;
    //check rows
    for(int i=0;i<A.size();i++){
        isPresent.clear();
        for(int j=0;j<A[i].size();j++){
            if(A[i][j] == '.')
                continue;
            int x = A[i][j] - '0';
            if(isPresent.find(x) != isPresent.end())
                return 0;
            else
                isPresent[x] = true;
        }
    }
    //check columns
    for(int i=0;i<9;i++){
        isPresent.clear();
        for(int j=0;j<A.size();j++){
            if(A[j][i] == '.')
                continue;
            int x = A[j][i] - '0';
            if(isPresent.find(x) != isPresent.end())
                return 0;
            else
                isPresent[x] = true;
        }
    }
    // check boxes;
    for(int k=0;k<=6;k+=3){
        
        for(int j=0;j<9;j++){
            if(j % 3 == 0)
                isPresent.clear();
            if(A[k][j] != '.'){
                int x = A[k][j] - '0';
                if(isPresent.find(x) != isPresent.end())
                    return 0;
                else
                    isPresent[x] = true;
            }
            if(A[k+1][j] != '.'){
                int x = A[k+1][j] - '0';
                if(isPresent.find(x) != isPresent.end())
                    return 0;
                else
                    isPresent[x] = true;
            }
            if(A[k+2][j] != '.'){
                int x = A[k+2][j] - '0';
                if(isPresent.find(x) != isPresent.end())
                    return 0;
                else
                    isPresent[x] = true;
            }
        }
    }
    return 1;
    
}
