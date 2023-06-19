class Solution {
public:
    vector<vector<string>> groupAnagrams(vector<string>& strs) {
        vector<vector<string>> ans;
        vector<string> s = strs;
        int n = strs.size();

        for(int i=0; i<n; i++){
            sort(s[i].begin(), s[i].end());
        }
        
        for(int i=0; i<n; i++){
            vector<string> str;
            if(strs[i] != "0"){
                str.push_back(strs[i]);
            }
            for(int j=i+1; j<n; j++){
                if(s[i] == s[j] && strs[j] != "0"){
                    str.push_back(strs[j]);
                    strs[j] = "0";
                }
            }
            if(str.size() > 0){
                ans.push_back(str);
            }
        }
        
        return ans;
    }
};