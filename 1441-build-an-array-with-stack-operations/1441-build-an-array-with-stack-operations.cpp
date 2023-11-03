class Solution {
public:
    vector<string> buildArray(vector<int>& target, int n) {
        vector<string> ans;
        int tIndex = 0;
        
        for(int i = 1 ; i <= n && tIndex < target.size() ; i++) {
            if(i == target[tIndex]) {
                ans.push_back("Push");
                tIndex++;
                
            } 
            else {
                ans.push_back("Push");
                ans.push_back("Pop");
            }
        }
        return ans;
    }
};