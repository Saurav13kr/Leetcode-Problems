class Solution:
    def maximumValueSum(self, nums: List[int], k: int, edges: List[List[int]]) -> int:
        ans=0
        c=0
        d=1<<30
        for num in nums:
            ans+=max(num, num1:=num^k)
            c^=num<num1
            d=min(d,abs(num-num1))
        return ans-d*c