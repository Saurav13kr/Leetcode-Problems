class Solution {
public:
    vector<string> removeSubfolders(vector<string>& folder) {
        unordered_set<string> st;
        for (auto fol : folder) 
            st.insert(fol);

        vector<string> ans;
        for (string str : folder) {
            string subFol = "";
            bool exist = false;
            for (char ch : str) 
            {                
                if (ch == '/' && st.find(subFol) != st.end()) {
                    exist = true;
                    break;
                }
                subFol += ch;
            }

            if (!exist) 
                ans.push_back(subFol);
        }

        return ans;
    }
};