class Solution {
public:
    int findSpecialInteger(vector<int>& arr) {
        unordered_map<int,int> m;
        for(auto i:arr){
            m[i]++;
        }
        for(auto it: m){
            if(it.second > (arr.size())/4 )
                return it.first;
        }
        return 0;
    }
};