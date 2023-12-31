class Solution {
public:
    int maxLengthBetweenEqualCharacters(string s) {
        vector<int> startIndex(26, -1);
        int ans = -1;
        for(int i=0 ; i<s.size() ; i++){
            char c = s[i];
            if(startIndex[c-'a'] != -1){
               
                int diff = i - startIndex[c-'a'] - 1;
                ans = max(ans, diff);
            }
            else{
                startIndex[c-'a'] = i;
            }
        }

        return ans;
    }
};