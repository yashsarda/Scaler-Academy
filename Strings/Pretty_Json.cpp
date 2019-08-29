// This function is used to add required tabs to the string
void addtabs(int t,string& to)
{
    for(int i=1;i<=t;i++)
        to += "\t";
}
vector<string> Solution::prettyJSON(string A) {
    // Remove spaces
    string s;
    for(int i=0;i<A.size();i++){
        if(A[i] == ' ')
            continue;
        s += A[i];
    }
    int n = s.size();
    // The pretty json string will always contain balanced parenthesis so we can use stack which 
    // will help in indentation and keeping the count of parenthesis
    // stack stores the number of openeing parenthesis before this parenthesis
    stack<char> st;
    vector<string> v;
    int i = 0;
    while(i < n){
        string to;
        int t = st.size();
        // If we encounter a '{' or '[' then first add the required tabs to the string, push it onto the stack
        // and just increment the pointer
        if(s[i] == '{'){
            addtabs(t,to);
            to += s[i];
            st.push('{');
            v.push_back(to);
            i++;
        }
        // If we encounter a '}' or ']' then we need to pop the top of stack.(Always the correct bracket will be poped 
        // since it's balanced). We need to subtract the number of tabs correctly.
        // Now only one case we need to consider.
        // If we have an array of object or in a object multiple arrays then they are going to be comma separated
        // So if the next character after this bracket is comma then just append this our current string since it 
        // is going to come in a single line
        else if(s[i] == '}'){
            st.pop();
            t--;
            addtabs(t,to);
            to += s[i];
            if(i + 1 < n && s[i+1] == ',')
                to += ',',i++;
            v.push_back(to);
            i++;
        }
        else if(s[i] == '['){
            addtabs(t,to);
            to += s[i];
            st.push('[');
            v.push_back(to);
            i++;
        }
        else if(s[i] == ']'){
            st.pop();
            t--;
            addtabs(t,to);
            to += s[i];
            if(i + 1 < n && s[i+1] == ',')
                to += ',',i++;
            v.push_back(to);
            i++;
        }
        // if it is not any bracket then there are cases. We need to examine the top of the stack
        else{
            char c = st.top();
            int f;
            addtabs(t,to);
            // If top is '{', then it a json object so we are definetely going to find ':' in the subsequent 
            // string. Find its position from the current character.
            // The value can be a string,integer,array or object. If it is an array or object then we need to push 
            // our curent string till colon in vector.
            // Now it might also be a case that the key: value might have been last. So just check if there
            // are other value(jsut find if we encounter a ',' or '}' first).
            if(c == '{'){
                f = s.find(":",i);
                if(s[f + 1] == '{' || s[f + 1] == '['){
                    to += s.substr(i,f-i+1);
                    v.push_back(to);
                    i = f + 1;
                }
                else{
                    for(int index=i+1;;index++){
                        if(s[index] == ',' || s[index] == '}'){
                            f = index;
                            break;
                        }
                    }
                    if(s[f] == ','){
                        to += s.substr(i,f-i+1);
                        i = f + 1;
                    }
                    else{
                        to += s.substr(i,f-i);
                        i = f;
                    }
                    v.push_back(to);
                }
            }
            // If the top of the stack is '[', then it is a json array. Now the array might contains multiple 
            // objects or a single object. If it contains multiple objects just find the first ',' and push into vector
            // If it is last object push our current string to vector
            else{
                for(int index=i+1;;index++){
                    if(s[index] == ',' || s[index] == ']'){
                        f = index;
                        break;
                    }
                }
                if(s[f] == ','){
                    to += s.substr(i,f-i+1);
                    i = f + 1;
                }
                else{
                    to += s.substr(i,f-i);
                    i = f;
                }
                v.push_back(to);
            }
        }
        
    }
    return v;
}
