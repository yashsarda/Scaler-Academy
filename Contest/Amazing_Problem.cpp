int Solution::solve(string A) {
    int len = A.length();
    if(len < 3)
        return 0;
    
    int index = 0;
    string find_w = "";
    string find_vv = "";
    while(index < len) {
        if(A[index] == 'w') {
            find_w += A[index];
        }
        else if(A[index] == 'v') {
            find_vv +=A[index];
        }
        index++;
        if(find_w == "w" || find_vv == "vv")
            break;
    }
    int answer = 0;
    while(index < len) {
        string find_o = "";
        while(index < len) {
            if(A[index++] == 'o') {
                find_o += "o";
                break;
            } 
        }
        if(find_o == "o") {
            find_w = "";
            find_vv = "";
           while(index < len) {
                if(A[index] == 'w') {
                    find_w += A[index];
                }
                else if(A[index] == 'v') {
                    find_vv +=A[index];
                }
                index++;
                if(find_w == "w" || find_vv == "vv")
                    break;
            }
            if(find_w == "w" || find_vv == "vv")
                answer++;
        }
    }
    return answer;
}
