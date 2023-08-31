class Solution {
public:
    int minTaps(int n, vector<int>& ranges) {
        int size = ranges.size();
        for (int i = 0; i < size; i++)
            ranges[max(0, i - ranges[i])] = i + ranges[i];      

        int currEnd = 0, nextEnd = 0, cnt = 1;
        for (int i = 0; i < size; i++) {
            if (currEnd < i) {        
                if (nextEnd < i)      
                    return -1;
                currEnd = nextEnd;    
                ++cnt;                  
            }
            nextEnd = max(nextEnd, ranges[i]);  
            if (nextEnd >= size - 1)      
                break;
        }
        return cnt;
    }
};