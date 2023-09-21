class Solution {
public:
  vector<double> medianSlidingWindow(vector<int>& nums, int k){
    int size = nums.size(), median_pos = k - k / 2 - 1;
    vector<double> res(size - k + 1);
    multiset<int> s(nums.begin(), nums.begin() + k);
    auto it = next(s.begin(), median_pos);

    for (auto i = k; i <= size; ++i) {
        res[i - k] = ((double)*it + (k % 2 != 0 ? *it : *next(it))) / 2;
        if (i < size) {

            int repos_it = INT_MAX; 
            if (k > 2){
 
                if ((nums[i - k] < *it && nums[i] < *it) || (nums[i - k] > *it && nums[i] > *it)) repos_it = 0;
                else if (nums[i - k] < *it && nums[i] > *it) repos_it = 1; 
                else if (nums[i - k] > *it && nums[i] < *it) repos_it = -1;
            }
            s.insert(nums[i]);
            s.erase(s.find(nums[i - k]));

            if (repos_it == INT_MAX) it = next(s.begin(), median_pos);
            else if (repos_it == 1) ++it;
            else if (repos_it == -1) --it;
        }
    }
    return res;
}
};