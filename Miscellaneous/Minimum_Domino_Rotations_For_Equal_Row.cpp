class Solution {
public:
    int minDominoRotations(vector<int>& A, vector<int>& B) {
        int len = A.size();
        if(len == 1)
            return 0;
        
        int first = A[0];
        int second = B[0];
        bool flag1 = true, flag2 = true;
        
        for(int i=1;i<len;i++) {
            if(A[i] != first && B[i] != first) {
                flag1 = false;
            }
        }
        for(int i=1;i<len;i++) {
            if(A[i] != second && B[i] != second) {
                flag2 = false;
            }
        }
        
        if(!flag1 && !flag2)
            return -1;
        int min_answer = INT_MAX;
        if(flag1) {
            int answer = 0;
            for(int i=1;i<len;i++) {
                if(A[i] == first)
                    continue;
                answer++;
            }
            min_answer = min(min_answer, answer);
        }
        if(flag2) {
            int answer = 0;
            for(int i=1;i<len;i++) {
                if(B[i] == second)
                    continue;
                answer++;
            }
            min_answer = min(min_answer, answer);
        }
        swap(first, second);
        if(flag2) {
            int answer = 1;
            for(int i=1;i<len;i++) {
                if(A[i] == first)
                    continue;
                answer++;
            }
            min_answer = min(min_answer, answer);
        }
        if(flag1) {
            int answer = 1;
            for(int i=1;i<len;i++) {
                if(B[i] == second)
                    continue;
                answer++;
            }
            min_answer = min(min_answer, answer);
        }
        return min_answer;
    }
};