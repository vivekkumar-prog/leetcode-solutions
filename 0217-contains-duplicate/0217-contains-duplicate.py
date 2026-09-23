class Solution:
    def containsDuplicate(self, nums: List[int]) -> bool:
        l1=set(nums)
        if(len(nums)==len(l1)):
            return False
        else:
            return True    
        