class Solution:
    def maxAverageRatio(self, cl: List[List[int]], es: int) -> float:
        hp = []
        n=len(cl)
        av=0
        
        for i,j in cl:
            diff = ((i+1)/(j+1)) - (i/j)
            heappush(hp,(-diff,i,j))
        
        for _ in range(es):
            _,i,j = heappop(hp)
            
            gain = ((i+2)/(j+2)) - ((i+1)/(j+1))
            heappush(hp, (-gain,i+1,j+1))
            
        for _,x,y in hp:
            av+=(x/y)
            
        return av/n      