void countSubSequences(vector<int>& A, int B, int sum, int& answer, int length, int index)
{
 
    if(length == B) {
        answer += (sum <= 1000);
        return;
    }
    
    if(length > B || index == A.size()) {
        return;
    }
    
    countSubSequences(A, B, sum, answer, length, index + 1);
    countSubSequences(A, B, sum + A[index], answer, length + 1, index + 1);    
}
int Solution::solve(vector<int> &A, int B) {
    int n = A.size();
    int answer = 0;
    
    countSubSequences(A, B, 0, answer, 0, 0);
    
    return answer;
}
