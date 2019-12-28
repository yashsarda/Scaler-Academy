vector<int> Solution::solve(vector<int> &A) {
    int len = A.size();
    int answer = 0;
    int temp = 0;
    int temp_start = -1;
    int start = -1;
    for(int i=0;i<len;i++) {
        if(A[i] < 0) {
            if(temp > answer) {
                start = temp_start;
                answer = temp;
            }
            temp_start = -1;
            temp = 0;
            continue;
        }
        temp++;
        if(temp_start == -1)
            temp_start = i;
    }
    if(temp > answer) {
        start = temp_start;
        answer = temp;
    }
    vector<int> v;
    if(answer == -1) return v;
    for(int i=start;i<start + answer;i++)
        v.push_back(A[i]);
    return v;
}
