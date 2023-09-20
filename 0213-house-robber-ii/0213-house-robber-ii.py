class Solution:
    def rob(self, nums: List[int]) -> int:
        if len(nums) == 1 : return nums[0]
        def helper(i,taken_0):
            if i >= n:
                return 0
            if (i,taken_0) in cache: return cache[i,taken_0]
            if i == n-1 :
                if taken_0 == 1 :
                    return 0
                else :
                    return nums[i]  
            pick = nums[i] + helper(i+2,taken_0)
            notPick = 0 + helper(i+1,taken_0)
            cache[i,taken_0] = max(pick,notPick)
            return max(pick,notPick)
        
        n = len(nums)
        cache = {}
        return max(helper(1,0),helper(0,1))