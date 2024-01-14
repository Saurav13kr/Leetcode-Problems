class Solution {
public:
    bool closeStrings(string word1, string word2) {
        if (word1.length() != word2.length()) {return false;}
        if (word1.length() == 0 || word1 == word2) {return true;}
        
        unordered_map<char,int>occ1, occ2;
        vector<char>keys1, keys2;
        vector<int>vals1, vals2;
        
        for (int i=0; i < word1.length(); i++) {
            occ1[word1[i]]++;
            occ2[word2[i]]++;
        }
        
        for (auto it = occ1.begin(); it != occ1.end(); ++it) {
            keys1.push_back(it->first);
            vals1.push_back(it->second);
        }
        for (auto it = occ2.begin(); it != occ2.end(); ++it) {
            keys2.push_back(it->first);
            vals2.push_back(it->second);
        }
        
        sort(keys1.begin(), keys1.end()); sort(keys2.begin(), keys2.end());
        sort(vals1.begin(), vals1.end()); sort(vals2.begin(), vals2.end());
        return keys1 == keys2 && vals1 == vals2;
    }
};