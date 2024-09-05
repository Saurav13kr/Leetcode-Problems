class Solution {
public:
    vector<int> missingRolls(vector<int>& rolls, int mean, int n) {
        long long sum = 0;
        for(int i = 0 ; i < rolls.size() ; i++){
            sum += rolls[i];
        }
        int m = rolls.size();
        long long x = (long long)mean*(n+m) - sum;
        if(x < n || x > 6*n){
            return {};
        }

        vector<int> ans;
        for(int i = 0 ; i < n ; i++){
            ans.push_back(1);
        }
        x -= n;
        for (int i = 0; i < n && x > 0; i++)
        {
            int add = min(5LL, x);
            ans[i] += add;
            x -= add;
        }
        return ans;
    }

};