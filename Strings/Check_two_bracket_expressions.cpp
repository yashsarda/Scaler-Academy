int Solution::solve(string A, string B) {
    int a = A.size();
    int b = B.size();
    stack<char> st;
    st.push('+');
    
    string first = "";
    string second = "";
    
    // Just remove the brackets from both of the string ans compare them
    for(int i=0;i<a;i++){
        // Just append the character to our string
        if(A[i] >= 'a' && A[i] <= 'z'){
            first += A[i];
        }
        // If it's a sign just look at the top of the stack and if the top of the stack is 
        // negative then the sign changes else it remains the same and then append to the string
        else if(A[i] == '-' || A[i] == '+'){
            char x = st.top();
            if(x == '-'){
                char toggle = (A[i] == '+') ? '-' : '+';
                first += toggle;
            }
            else{
                first += A[i];
            }
        }
        // If it's a opening bracket then we are going to have a sign before it, we need to push this sign on to the
        // stack. If the top of the stack is negative the the sign is toggled else it remains the same
        else if(A[i] == '('){
            if(i > 0){
                char x = st.top();
                if(x == '-'){
                    char toggle = (A[i - 1] == '+') ? '-' : '+';
                    st.push(toggle);
                }
                else
                    st.push(A[i-1]);
            }
        }
        else if(A[i] == ')'){
            if(!st.empty())
                st.pop();
        }
    }
    
    while(!st.empty())
        st.pop();
    st.push('+');
    for(int i=0;i<b;i++){
        if(B[i] >= 'a' && B[i] <= 'z'){
            second += B[i];
        }
        else if(B[i] == '-' || B[i] == '+'){
            char x = st.top();
            if(x == '-'){
                char toggle = (B[i] == '+') ? '-' : '+';
                second += toggle;
            }
            else{
                second += B[i];
            }
        }
        else if(B[i] == '('){
            if(i > 0){
                char x = st.top();
                if(x == '-'){
                    char toggle = (B[i - 1] == '+') ? '-' : '+';
                    st.push(toggle);
                }
                else
                    st.push(B[i-1]);
            }
        }
        else if(B[i] == ')')
            st.pop();
    }
    
    return (first == second);
    
    
    
}
