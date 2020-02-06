vector<vector<char> > B;
bool check_row(int row_number, char value)
{
    for(int i=0;i<9;i++) {
        if(B[row_number][i] == value)
            return false;
    }
    return true;
}

bool check_column(int column_number, char value)
{
    for(int i=0;i<9;i++) {
        if(B[i][column_number] == value) 
            return false;
    }
    return true;
}

bool check_box(int row, int column, char value)
{
    // Find which box does this cell belong to
    int start_row = row / 3 * 3;
    int start_column = column / 3 * 3;
    int end_row = start_row + 2;
    int end_column = start_column + 2;
    
    for(int i=start_row;i<=end_row;i++) {
        for(int j=start_column;j<=end_column;j++) {
            if(B[i][j] == value)
                return false;
        }
    }
    
    return true;
}
bool isSolved(int& r, int& c)
{
    for(int i=0;i<9;i++) {
        for(int j=0;j<9;j++) {
            if(B[i][j] == '.') {
                r = i;
                c = j;
                return false;
            }
        }
    }
    return true;
}
bool checkSudoku()
{
    int r, c;
    // Base case
    if(isSolved(r, c)) {
        return true;
    }
    for(char i='1';i<='9';i++) {
        if(check_row(r, i) && check_column(c, i) && check_box(r, c, i)) {
            B[r][c] = i;
            if(checkSudoku())
                return true;
            B[r][c] = '.';
        }
    }
    return false;
}
void Solution::solveSudoku(vector<vector<char> > &A) {
    // Do not write main() function.
    // Do not read input, instead use the arguments to the function.
    // Do not print the output, instead return values as specified
    // Still have a doubt. Checkout www.interviewbit.com/pages/sample_codes/ for more details
    B.clear();
    B.resize(9);
    for(int i=0;i<9;i++)
        B[i].resize(9);
    
    for(int i=0;i<9;i++) {
        for(int j=0;j<9;j++) {
            B[i][j] = A[i][j];
        }
    }
    
    bool answer = checkSudoku();
    for(int i=0;i<9;i++) {
        for(int j=0;j<9;j++) {
            A[i][j] = B[i][j];
        }
    }
}
