// There are just a lot of cases to cover in overlapping rectangle
// Instead we consider the time when rectangle do not overlap
// Totally boring question
int Solution::solve(int A, int B, int C, int D, int E, int F, int G, int H) {
    if(G <= A  || C <= E)
        return 0;
    if(F >= D || B >= H)
        return 0;

    return 1;
 }
