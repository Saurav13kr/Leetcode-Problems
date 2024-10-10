#include <vector>
#include <utility>
class Solution {
public:

    vector<pair<int,int>>st;
    int maxWidthRamp(vector<int>& nums) {
        int mn = 99999999;
        int last = 0 , best_ans = 0;
        st.push_back(make_pair(nums[0], 0 ) );

        for(int i = 1 ; i < nums.size() ; ++i ){
            if(nums[i] < st[last].first) {
                st.push_back(make_pair(nums[i] , i ));
                last++;
            }
        }

        for(int i = nums.size() - 1 ; i >= 0 ; --i){
          
            int l = -1 , r = st.size(), mid;

            while(l + 1 != r){
                mid = l + r >> 1;
                if( st[mid].first <= nums[i] ){
                    r = mid;
                }
                else l = mid;
            }

            if(st[r].second <= i)
            {
                best_ans = max(best_ans, i - st[r].second);
            }

        }
        return best_ans;
    }
};