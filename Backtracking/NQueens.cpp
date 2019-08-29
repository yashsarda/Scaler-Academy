vector<bool> column, diagonal1,diagonal2;
// Always pass things by reference 
void solve(int row,int A,vector<vector<string> >& ans,int& count,vector<int>& place)
{
    if(row == A){
        // If i'm at this row then all the queens are already placed
        vector<string> v(A); 
        for(int i=0;i<A;i++){
            int queen_is_placed = place[i];
            string s;
            for(int j=0;j<A;j++){
                if(j == place[i])
                    s+= 'Q';
                else
                    s+= '.';
            }
            v[i] = s;
        }
        ans.push_back(v);
        count++;
        return;
    }
    
    for(int i=0;i<A;i++){
        // Check if the queen is safe to keep 
        if(!column[i] && !diagonal1[row - i + A  - 1] && !diagonal2[row + i]){
            column[i] = diagonal1[row - i + A  - 1] = diagonal2[row + i] = 1;
            place[row] = i;
            solve(row + 1,A,ans,count,place);
            place[row] = -1;
            // We get out of the recursion, then reset the values because we are going to try different configuration
            column[i] = diagonal1[row - i + A  - 1] = diagonal2[row + i] = 0;
        }
    }
}
vector<vector<string> > Solution::solveNQueens(int A) {
    column.clear();
    diagonal1.clear();
    diagonal2.clear();
    column.resize(1500);
    diagonal1.resize(1500);
    diagonal2.resize(1500);
    vector<vector<string> > ans;
    int count = 0;
    vector<int> place(A);
    solve(0,A,ans,count,place);
    return ans;
}
