class Solution:
    # @param A : list of integers
    # @param B : string
    # @return a strings
    def solve(self, A, B):
        n = len(A)
        B = int(B)
        new_A = []
        for i in range(n // 2, n):
            new_A.append(A[i])
        
        lb = new_A[0]
        ub = new_A[-1] + B
        
        final_answer = 0
        while lb <= ub:
            mid = lb + (ub - lb) // 2
            answer = 0
            for element in new_A:
                if element >= mid:
                    break
                answer += mid - element
            
            if answer <= B:
                final_answer = mid
                lb = mid + 1
            else:
                ub = mid - 1
        
        return str(final_answer)    
