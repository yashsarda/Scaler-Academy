int Solution::solve(int A, int B, int C, int D, int E, int F, int G, int H) {

    // condition for non overlapping
    if(G <= A || C <= E)
        return 0;
    if(H <= B || D <= F)
        return 0;

    // just take an example and find the corner points
    int topx = max(A,E);
    int topy = max(B,F);
    int bottomx = min(C,G);
    int bottomy = min(D,H);

    return (bottomx - topx) * (bottomy - topy);
}
