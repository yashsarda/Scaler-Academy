// leetcode
class Solution {
public:
    int minSwap(vector<int>& A, vector<int>& B) {
        int len = A.size();
        if(len == 1)
            return 0;
        
        int not_swapped_1 = 0;
        int swapped_1 = 1;
       
        for(int i=1;i<len;i++) {
            int not_swapped_2 = INT_MAX, swapped_2 = INT_MAX;
            if(A[i - 1] < A[i] && B[i - 1] < B[i]) {
                not_swapped_2 = min(not_swapped_2, not_swapped_1);
                swapped_2 = min(swapped_2, swapped_1 + 1);
            }
            if(A[i - 1] < B[i] && B[i - 1] < A[i]) {
                not_swapped_2 = min(not_swapped_2, swapped_1);
                swapped_2 = min(swapped_2, not_swapped_1 + 1);
            }
            not_swapped_1 = not_swapped_2;
            swapped_1 = swapped_2;
        }
        return min(not_swapped_1, swapped_1);
    }
};