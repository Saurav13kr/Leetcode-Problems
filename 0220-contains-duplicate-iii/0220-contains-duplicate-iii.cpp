class Solution {
public:
    bool containsNearbyAlmostDuplicate(vector<int>& nums, int indexDiff, int valueDiff) {      
     set<int>ak;
     unordered_map<int,int>bk;
     for(int i=0;i<=indexDiff;i++) {
        if(i==nums.size())
        break;
         
        bk[nums[i]]++;        
        ak.insert(nums[i]);
     }
        
     int j=indexDiff+1;
     for(int i=0;i<nums.size();i++){
      bk[nums[i]]--;
      if(bk[nums[i]]==0)
      ak.erase(nums[i]);
      auto a=ak.lower_bound(nums[i]);
      int maxi=1e8;
      if(a!=ak.end()){        
         maxi=abs(nums[i]-(*a));
      }
      if(a!=ak.begin())
      a--;
      if(a!=ak.end())
      maxi=min(maxi,abs(nums[i]-(*a)));

      if(maxi<=valueDiff){
         return true;
      }
      if(j<nums.size()){
         bk[nums[j]]++;
         ak.insert(nums[j]);
         j++;
      }
     }
     return false;
    }
};