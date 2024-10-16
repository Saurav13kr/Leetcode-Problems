class Solution {
public:
    string longestDiverseString(int a, int b, int c) {
        priority_queue<pair<int,char>> maxHeap; 
        if(a > 0) maxHeap.push({a, 'a'});
        if(b > 0) maxHeap.push({b, 'b'});
        if(c > 0) maxHeap.push({c, 'c'});

        string result = "";
        while(!maxHeap.empty())
        {
            int count = maxHeap.top().first;
            int charac = maxHeap.top().second;
            maxHeap.pop();

            if(result.size() >= 2 && result.back() == charac && result[result.size() - 2] == charac){
                if(maxHeap.empty()) break;

                auto [count2, charac2] = maxHeap.top();
                maxHeap.pop();

                result += charac2;
                if(--count2 > 0) maxHeap.push({count2, charac2});
                maxHeap.push({count, charac});
            }else{
                result += charac;
                if(--count > 0) maxHeap.push({count, charac});
            }
        }

        return result;
    }
};