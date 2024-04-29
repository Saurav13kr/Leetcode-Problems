class Solution {
public:
    int minOperations(vector<int>& nums, int k) {
      int x = 0;
        for (int i : nums) {
            x ^= i;
        }

        x ^= k;
        int count = 0;
        while (x > 0) {
            count += x & 1;
            x >>= 1;
        }
        return count;
    }
};