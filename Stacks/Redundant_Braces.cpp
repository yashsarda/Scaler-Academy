// Count the number of operation, If the number of valid parenthis is equal to the number of operation
// then there are no redundant parenthesis else there are
int Solution::braces(string A) {
    int si = A.size();
    stack<int> s;
    int number_of_operation = 0;
    for(int i=0;i<si;i++){
        if(A[i] == '+' || A[i] == '-' || A[i] == '*' || A[i] == '/')
            number_of_operation++;
    }
    for(int i=0;i<si;i++){
        if(A[i] == '('){
            s.push(i);
        }
        else if(A[i] == ')'){
            int top = s.top();
            s.pop();
            if(i - top <= 2)
                return 1;
            number_of_operation--;
            if(number_of_operation < 0)
                return 1;
        }
    }
    return 0;
}
