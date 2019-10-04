// leetcode problem
class Solution {
public:
    vector<vector<bool> > visited;
    bool processRows(int x,int y,int i, int j)
    {
        if(abs(y - j) == 1)
            return true;
        return visited[x][1];
    }
    bool processColumn(int x, int y, int i,int j)
    {
        if(abs(x - i) == 1)
            return true;
        return visited[1][y];
    }
    bool processDiagonal(int x,int y, int i, int j)
    {
        if(abs(x-i) == 2 && abs(y - j) == 2)
            return visited[1][1];
        
        return true;
    }
    void countPatterns(int x, int y, int m, int n, int number,int& answer)
    {
        if(number == n) {
            ++answer;
            return;
        }
        if(number >= m)
            ++answer;
        
        for(int i=0;i<3;i++) {
            for(int j=0;j<3;j++) {
                if(!visited[i][j]) {
                    // same row
                    if(x == i && y != j) {
                        if(processRows(x,y,i,j)) {
                             // if(x == 0 && y == 1)
                             //    cout << i << ' ' << j << '\n';
                            visited[i][j] = true;
                            countPatterns(i,j,m,n,number + 1, answer);
                            visited[i][j] = false;
                        }
                        
                    }
                    // same column
                    else if(y == j && x != i) {
                         // if(x == 0 && y == 1)
                         //    cout << i << ' ' << j << '\n';
                        if(processColumn(x,y,i,j)) {
                            visited[i][j] = true;
                            countPatterns(i,j,m,n,number + 1, answer);
                            visited[i][j] = false;
                        }
                    }
                    // same diagonal
                    else if (x + y == i + j || j - i == y - x) {
                         // if(x == 0 && y == 1)
                         //    cout << i << ' ' << j << '\n';
                        if(processDiagonal(x,y,i,j)) {
                            visited[i][j] = true;
                            countPatterns(i,j,m,n,number + 1, answer);
                            visited[i][j] = false;
                        }
                    }
                    else {
                        // if(x == 0 && y == 1)
                        //     cout << i << ' ' << j << '\n';
                        visited[i][j] = true;
                        countPatterns(i,j, m,n,number + 1,answer);
                        visited[i][j] = false;
                    }
                }
            }
        }
    }
    int numberOfPatterns(int m, int n) {
        int answer = 0;
       
        for(int i=0;i<3;i++) {
            for(int j=0;j<3;j++) {
                visited.clear();
                visited.resize(3);
                for(int k=0;k<3;k++)
                    visited[k].resize(3, false);
                visited[i][j] = true;
                countPatterns(i,j,m,n,1,answer);
                //cout << i << ' ' << j << ' ' << answer << '\n';
            }
        }
        return answer;
    }
};