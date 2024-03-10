class Solution {
public:
    vector<int> intersection(vector<int>& nums1, vector<int>& nums2) {
        unordered_map<int,int> a;
        vector<int> result;
        for(int i=0;i<nums1.size();i++)
            a[nums1[i]]++;
        for(int i=0;i<nums2.size();i++)
        {
            if(a[nums2[i]]>=1)
            {
                result.push_back(nums2[i]);
                a[nums2[i]] = 0;
            }
        }  
        return result;   
    }
};