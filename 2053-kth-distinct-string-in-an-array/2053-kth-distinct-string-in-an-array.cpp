class Solution {
public:
    string kthDistinct(vector<string>& arr, int k) {
        unordered_map<string,int>d;
        for(auto&x : arr){
            d[x]++;
        }

        string ans = "";
        int count  = 0;
        for(auto& x : arr)
        {
            if(d[x]==1){
                ans = x;
                count++;
            }

            if(count == k){
                return ans;
            }
        }

        return "";
        
    }
};