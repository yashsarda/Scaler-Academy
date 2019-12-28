string Solution::solve(vector<int> &A) {
    double area = 0;
    area += 0.5 * A[0];
    
    for(int i=0;i<A.size()-1;i++) {
        area += abs(A[i+1]-A[i]) * 0.5;
        area += min(A[i+1],A[i]);
    }
    int n = A.size();
    area += 0.5 * A[n-1];
    long long roundedArea = round(area);
    return to_string(roundedArea);
}