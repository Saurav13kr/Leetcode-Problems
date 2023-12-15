class Solution {
public:
    vector<string> findRepeatedDnaSequences(string s) {
        unordered_map<string,int>mp;
        set<string>st;
        vector<string>ans;
        int n=s.size();
        for(int i=0;i<n-9;++i)
        {
            string str=s.substr(i,10);
            if(mp.find(str)!=mp.end())
            {
                // mp[str]++;
                st.insert(str);

            }
            mp[str]++;
        }
        for(auto it:st)
        {
            ans.push_back(it);
        }
        return ans;
        
    }
};