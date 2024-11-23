class Solution {
public:
    long long dividePlayers(vector<int>& skill) {
        int min_val = skill.front(), max_val = skill.front(), sum = 0;
        for(auto&& s : skill) {
            min_val = min_val > s ? s : min_val;
            max_val = max_val < s ? s : max_val;
            sum += s;
        }
        int skill_sum = min_val + max_val;
        if(sum != skill.size() / 2 * skill_sum) return -1;
        double mid = (double)skill_sum / 2;
        long long res = 0;
        int valid = 0, l_count = 0, s_count = 0;
        for(auto&& s : skill) 
        {
            if(s > mid) {
                valid ^= (skill_sum - s);
                l_count++;
            } 
            else {
                valid ^= s;
                if(s < mid) s_count++;
            }
            res += s * (skill_sum - s);
        }
        return (!valid && (s_count == l_count)) ? res/2 : -1;
    }
};