// Since we have to do in place we use first row as our reference array
// We go through the column to see whether there is any zero in our column. If there we mark the first row and that column as zero
// We start iterating from the second row and keep a variable indicating whether there is a zero in that row
// If there is a zero in that row or a zero in that column we mark it as 0. To check for the column we just go to the first row and check that respective column
void Solution::setZeroes(vector<vector<int> > &A) {
    // Do not write main() function.
    // Do not read input, instead use the arguments to the function.
    // Do not print the output, instead return values as specified
    // Still have a doubt. Checkout www.interviewbit.com/pages/sample_codes/ for more details

    int rows = A.size();
    int columns = A[0].size();
    bool first_row_contains_zero = false;
    for(int i=0;i<columns;i++){
        if(A[0][i] == 0){
            first_row_contains_zero = true;
            break;
        }
    }
    for(int i=0;i<columns;i++){
        for(int j=1;j<rows;j++){
            if(A[j][i] == 0)
                A[0][i] = 0;
        }
    }

    for(int i=1;i<rows;i++){
        bool row_contains_zero = false;
        for(int j=0;j<columns;j++){
            if(A[i][j] == 0){
                row_contains_zero = true;
                break;
            }
        }
        for(int j=0;j<columns;j++){
            if(row_contains_zero || A[0][j] == 0)
                A[i][j] = 0;
        }
    }

    if(first_row_contains_zero){
        for(int i=0;i<columns;i++)
            A[0][i] = 0;
    }


}
