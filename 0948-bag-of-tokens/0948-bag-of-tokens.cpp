class Solution {
public:
    int bagOfTokensScore(vector<int>& tokens, int power) {
        int n = tokens.size();

        if(n == 1 and power >= tokens[0]) return 1;

        sort(tokens.begin(), tokens.end());

        int i = 0;
        int j = n-1;
        int ans = 0;
        int cur = 0;

        while(i <= j){
            while(i <= j and power >= tokens[i]){
                power -= tokens[i];
                i++;
                cur++;
            }

            ans = max(ans, cur);

            if(cur >= 1 and power < tokens[i]){
                power += tokens[j];
                j--;
                cur--;
            } else {
                return 0;
            }

            ans = max(ans, cur);
            // 
        }

        ans = max(ans, cur);

        return ans;
    }
};