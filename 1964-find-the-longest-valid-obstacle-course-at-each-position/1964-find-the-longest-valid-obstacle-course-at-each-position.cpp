class Solution {
public:
    vector<int> longestObstacleCourseAtEachPosition(vector<int>& S) {
        vector<int> ans;
        int len=0;
        
        for (int b:S) 
        {
            int a=upper_bound(begin(S),begin(S)+len,b)-begin(S); // b should be put at lis[a]
            S[a] = b;
            
            len = max(a+1, len); 
            ans.push_back(a+1);
        }
        
        return ans;
    }
};