class Solution {
public:
    bool isPathCrossing(string path) {
        int x=0;
        int y=0;
        unordered_set<int>s{0};
        int curr = x+(1e5)*y;
        for(auto i:path){
            if(i=='N') y++;
            else if(i=='S') y--;
            else if(i=='E') x++;
            else x--;
            curr = x+(1e5)*y;
            if(s.count(curr)) return true;
            s.insert(curr);
        }
        return false;
    }
};