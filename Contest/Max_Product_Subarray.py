class Solution:
	# @param A : tuple of integers
	# @return an integer
	def maxProduct(self, A):
	    A = list(A)
	    miniVal = maxiVal = answer = A[0]
	    for index,element in enumerate(A):
	        if index == 0:
	            continue
	        if element < 0:
	            miniVal, maxiVal = maxiVal, miniVal
	        maxiVal = max(element, element * maxiVal)
	        miniVal = min(element, element * miniVal)
	        answer = max(answer, maxiVal)
	    return answer
