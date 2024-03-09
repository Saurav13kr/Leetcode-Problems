class Solution {
public:
    int bSearch(vector<int> &a,int num,int low,int high){
        int ans = -1;
        while(low <= high){
            int mid = (low+high)/2;
            if(a[mid] == num) return num;
            else if(a[mid] > num){
                high = mid-1;
            }
            else low = mid+1;
        }
        return ans;
    }
    int getCommon(vector<int>& nums1, vector<int>& nums2) {
        for(int i = 0;i<nums1.size();i++){
            if(bSearch(nums2,nums1[i],0,nums2.size()-1) == nums1[i]){
                return nums1[i];
            }
        }
        return -1;
    }
};