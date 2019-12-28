int Solution::majorityElement(const vector<int> &A) {
    int n = A.size();
    int counter = 1;
    int answer = A[0];
    for(int i=1;i<n;i++) {
        if(A[i] == answer) 
            counter++;
        else
            counter--;
        if(counter < 0) {
            answer = A[i];
            counter = 1;
        }
    }
    counter = 0;
    for(int i=0;i<n;i++) 
        counter += (A[i] == answer);
    
    if(counter > n / 2)
        return answer;
}
