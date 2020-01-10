# Definition for singly-linked list.
# class ListNode:
#	def __init__(self, x):
#		self.val = x
#		self.next = None

class Solution:
	# @param A : head node of linked list
	# @return the head node in the linked list
	def deleteDuplicates(self, A):
	    if A is None or A.next is None:
	        return A
	    previous = A
	    current = A.next
	    nex = None
	    
	    while current is not None:
	        if current.val == previous.val:
	            nex = current
	            del nex
	        else:
	            if previous.next != current:
	                previous.next = current
	            previous = current
	        current = current.next
	    previous.next = None
	    return A
	    
	    
