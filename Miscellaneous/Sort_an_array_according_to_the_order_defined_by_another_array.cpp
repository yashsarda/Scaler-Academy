vector<int> Solution::solve(vector<int> &A, vector<int> &B) {
    int lena = A.size();
    int lenb = B.size();
    
    unordered_map<int, int> counterA;
    unordered_map<int, bool> isPresentB;
    
    for(int x: A) {
        counterA[x]++;
    }
    
    vector<int>  answer;
    for(int x: B) {
        isPresentB[x] = true;
        if(counterA.find(x) != counterA.end()) {
            int count = counterA[x];
            while(count -- > 0) {
                answer.push_back(x);
            }
        }
    }
    sort(A.begin(), A.end());
    
    for(int x: A) {
        if(isPresentB.find(x) == isPresentB.end()) {
            answer.push_back(x);
        }
    }
    return answer;
    
}
