class Solution {
public:
    int findLeastNumOfUniqueInts(vector<int>& arr, int k) {
        unordered_map<int, int> mp;
        
        int unique = 0;

        for(int ele: arr) {
            if( mp.find(ele) == mp.end() )
                unique++;
            mp[ele]++;
        }


        vector<int> counts;

        for(auto ele: mp)
            counts.push_back(ele.second);
    
        sort(counts.begin(), counts.end());

        int removed = 0;
        for(int ele: counts) {
            removed+=ele;
            if( removed <= k )
                unique--;
            else break;
        }

        return unique;
    }
};