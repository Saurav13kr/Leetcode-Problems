class Solution {
public:
    int find_pivot(vector<int>& nums, int l, int r) {
        while(l < r) {
            int mid = l + (r-l)/2;
            
            if(nums[mid] > nums[r]) {
                l = mid+1;
            } else {
                r = mid;
            }
        }
        return r;
    }
    
    int BS(int left,int right,vector<int>& nums,int target) {
        int idx=-1;
        while(left<=right) {
            int mid=left+(right-left)/2;
            if(nums[mid]== target) {            
                return mid;
            } else if(nums[mid]<target)
            {
                left=mid+1;
            } else{
                right=mid-1;
            }
        }
        return -1;
    }
    int search(vector<int>& nums, int target) {
        int n = nums.size();
        int pivot = find_pivot(nums, 0, n-1);

        if(nums[pivot] == target)
            return pivot;

        int idx = -1;
        idx= BS(0,pivot-1,nums,target);
        
        if(idx != -1){
            return idx;
        }
        idx= BS(pivot+1,n-1,nums,target);
        return idx;
    }
};