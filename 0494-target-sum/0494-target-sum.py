class Solution:
    def findTargetSumWays(self, nums: List[int], target: int) -> int:
        @cache
        def calculate(idx, sumVal):
            if idx==n:
                if sumVal==target:
                    return 1
                else:
                    return 0
            else:
                val1 = sumVal + nums[idx]
                val2 = sumVal - nums[idx]
                return calculate(idx+1, val1)+calculate(idx+1, val2)
            
        n = len(nums)
        
        return calculate(0, 0)