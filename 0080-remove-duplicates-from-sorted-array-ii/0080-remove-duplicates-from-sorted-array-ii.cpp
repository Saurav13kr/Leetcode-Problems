class Solution {
public:
    int removeDuplicates(vector<int>& nums) {
        int count = 1;  
        int i = *(nums.begin());  
        
        for (auto i = nums.begin() + 1; i != nums.end(); i++) {
            if (*i == *(i - 1)) {
                count++;  
                if (count > 2) {
                    nums.erase(i);  
                    i--;  
                }
            } 
            else {
                count = 1; 
            }
        }
        return nums.size(); 
    }
};
