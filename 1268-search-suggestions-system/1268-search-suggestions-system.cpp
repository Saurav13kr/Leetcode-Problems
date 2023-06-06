class Solution {
public:
    vector<vector<string>> suggestedProducts(vector<string>& products, string searchWord) {
        sort(products.begin(), products.end());
        unordered_map<string, vector<string>> mp;
        
        for (string &product : products) {
            string sub = "";
            for (int i=0; i < product.size(); i++) {
                sub.push_back(product[i]);
                if (mp[sub].size() < 3) 
                    mp[sub].push_back(product);
            }
        }
        
        vector<vector<string>> ans;
        string subStr = "";
        for (int i = 0; i < searchWord.size(); i++) {
            subStr += searchWord[i];
            ans.push_back(mp[subStr]);
        }
        return ans;
    }
};