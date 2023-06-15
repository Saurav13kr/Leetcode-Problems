class Solution {
public:
    double findMedianSortedArrays(vector<int>& nums1, vector<int>& nums2) {
        int s1 = nums1.size();  
        int s2 = nums2.size();
        int s = s1 + s2;  
        
        if(s2 == 0)
            return s1%2?nums1[s1/2]:(nums1[s1/2-1]+nums1[s1/2]) / 2.0;
        if(s1 == 0)
             return s2%2?nums2[s2/2]:(nums2[s2/2-1]+nums2[s2/2]) / 2.0;

        nums1.resize(s);
        int i = 0;
        int j = 0;

        while(i < s1) {
            if(nums1[i] > nums2[0]) {
                swap(nums1[i], nums2[0]); 
                rearrangeArray(nums2); 
            }
            i++;
        }

        while(j<nums2.size()) 
            nums1[i++] = nums2[j++];
        
    return s%2?nums1[s/2]:(nums1[s/2-1] + nums1[s/2]) / 2.0;     
    }
    
    void rearrangeArray(vector<int> & nums2) {

        for(int i=1; i<nums2.size() && nums2[i]<nums2[i-1]; i++)
            swap(nums2[i], nums2[i-1]);
    }
};