string convert(int A)
{
    stringstream ss;
    ss << A;
    return ss.str();
}
string Solution::solve(vector<vector<int> > &A) {
    int row = A.size();
    int col = A[0].size();
    
    for(int i=0;i<row;i++){
        for(int j=0;j<col;j++){
            A[i][j] = -A[i][j];
        }
    }
    
    string concat = "";
    for(int j=0;j<2;j++){
        for(int i=0;i<col;i++){
            string t = convert(A[0][i]);
            concat += t;
        }
    }
    for(int i=1;i<row;i++){
        string temp = "";
        for(int j=0;j<col;j++){
            string t = convert(A[i][j]);
            temp += t;
        }
        int found = concat.find(temp);
        if(found == string::npos)
            return "NO";
    }
    return "YES";
}
