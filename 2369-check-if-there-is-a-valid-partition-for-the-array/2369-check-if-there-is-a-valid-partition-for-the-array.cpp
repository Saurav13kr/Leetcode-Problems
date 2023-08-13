class Solution {
public:
    bool validPartition(vector<int>& nums) {        
        int n = nums.size();
        vector<int> dp(n,-1);
        return helper(nums, dp, 0, n);
    }

    bool helper(vector<int> &arr, vector<int> &dp, int start_indx, int n){

        if(start_indx >= n)
            return true;

        if(dp[start_indx] != -1)
            return dp[start_indx];

        if(start_indx + 1 < n && arr[start_indx] == arr[start_indx + 1])
        {

            if(helper(arr, dp, start_indx + 2, n))
            {
 
                dp[start_indx] = 1;

                return true;
            }

            if(start_indx + 2 < n && arr[start_indx] == arr[start_indx +2])
            {

                if(helper(arr, dp, start_indx + 3, n))
                {

                    dp[start_indx] = 1;
                    
                    return true;
                }
            }
        }

        if(start_indx + 2 < n && arr[start_indx + 1] - arr[start_indx] == 1 && arr[start_indx+2] - arr[start_indx] == 2)
        {

            if(helper(arr, dp, start_indx+3, n))
            {

                dp[start_indx] = 1;

                return true;
            }
        }

        dp[start_indx] = 0;

        return false;
    }
    
};