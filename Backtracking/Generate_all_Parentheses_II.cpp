/*
To form a well balanced string of paranthesis, it's necessary that the number of open braces
is always greater than equal to number of close braces


*/
void findAllAnswers(string intermediate, int A, vector<string>& answer, int num_open, int num_close)
{
    // Base case
    if(num_open == A && num_open == num_close) {
        answer.push_back(intermediate);
        return;
    }
    
    if(num_open < A) {
        intermediate += "(";
        findAllAnswers(intermediate, A, answer, num_open + 1, num_close);
        intermediate.pop_back();
    }
    
    if(num_open > num_close) {
        intermediate += ")";
        findAllAnswers(intermediate, A, answer, num_open, num_close + 1);
        intermediate.pop_back();
    }
    
}
vector<string> Solution::generateParenthesis(int A) {
    vector<string> answer;
    if(A == 1) {
        answer.push_back("()");
        return answer;
    }
    
    string temp = "";
    findAllAnswers(temp, A, answer, 0, 0);
    return answer;
}
