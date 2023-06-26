class Solution {
public:
     vector<int> findRightInterval(vector<vector<int>>& intervals) {
        vector<int> res;
        map<int,int> m;
         
        for(int i=0;i<intervals.size();i++) {  
            m[intervals[i][0]]=i;    
        }
         
        for(int i=0;i<intervals.size();i++) {
            auto it=m.lower_bound(intervals[i][1]);
            
            if(it==m.end())
                res.push_back(-1);
            else
                res.push_back(it->second);
        }
         
        return res;
    }
};