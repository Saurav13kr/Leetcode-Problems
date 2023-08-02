class Solution {
public:
    std::vector<std::vector<int>> permute(std::vector<int>& nums) {
        std::vector<std::vector<int>> allPermutations;
        std::vector<int> currentPermutation;
        search(nums, allPermutations, currentPermutation);
        return allPermutations;
    }

private:
    void search(std::vector<int>& nums, std::vector<std::vector<int>>& allPermutations, std::vector<int>& currentPermutation){
        if (!nums.size()) allPermutations.emplace_back(currentPermutation);
        else {
            for (int i = 0; i < nums.size(); i++) {
                int num = nums[i];
                nums.erase(nums.begin() + i);
                currentPermutation.emplace_back(num);
                search(nums, allPermutations, currentPermutation);
                currentPermutation.pop_back();
                nums.insert(nums.begin() + i, num);
            }
        }
    }
};