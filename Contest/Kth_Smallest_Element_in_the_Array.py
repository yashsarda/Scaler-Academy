class Solution:
	# @param A : tuple of integers
	# @param B : integer
	# @return an integer
	def kthsmallest(self, A, B):
	    A = list(A)
	    lower = min(A)
	    upper = max(A)
	    
	    while lower <= upper:
	        mid = (lower + upper) // 2
	        lessThan = equalTo = 0
	        for element in A:
	            if element == mid:
	                equalTo += 1
	            if element < mid:
	                lessThan += 1
	       
	        if lessThan < B and lessThan + equalTo >= B:
	            return mid
	       
	        if lessThan >= B:
	            upper = mid - 1
	        else:
	            lower = mid + 1
	    
