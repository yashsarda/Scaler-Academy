
// Problem statement
// Rishik is participating in a 100 people race. He is currently at Ath place. You are given N events in form of integer array B. 
// B[i] denotes that B[i] + 1 th ranked participant overtakes B[i]th ranked participant in chronological order. Find final rank of Rishik.

int Solution::solve(int A, vector<int> &B) {
    int len = B.size();
    int rank = A;
    for(int element: B) {
        if(element == rank)
            rank++;
        else if(element == rank - 1)
            rank--;
    }
    return rank;
}
