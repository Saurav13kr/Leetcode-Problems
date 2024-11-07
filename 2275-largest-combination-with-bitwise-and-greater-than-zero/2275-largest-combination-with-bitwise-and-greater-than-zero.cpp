class Solution {
public:
    int largestCombination(vector<int>& candidates) {
        vector<int> bits(24,0);

        for (int num : candidates) {
            int cnt = 0;
            while (num > 0){
                if (num % 2) bits[cnt]++;
                cnt++;
                num /= 2;
            }
        }

        return *std::max_element(bits.begin(), bits.end());
    }
};