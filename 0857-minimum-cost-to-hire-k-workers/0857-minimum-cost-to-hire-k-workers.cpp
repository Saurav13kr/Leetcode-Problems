class Solution {
public:
    double mincostToHireWorkers(vector<int>& quality, vector<int>& wage, int k) {
        const size_t n = quality.size();

        const auto cmp_ratio_less = [] (int32_t i, int32_t j) -> bool {
            return (j >> 16) * (i & 0xFFFF) < (i >> 16) * (j & 0xFFFF);
        };

        const auto as_ratio = [] (int32_t i) -> double {
            return static_cast<double>(i & 0xFFFF) / (i >> 16);
        };

        std::vector<int32_t> workers = std::move(wage);
        for (int i = 0; i < n; ++i)
            workers[i] |= quality[i] << 16;

        auto hiredEnd = workers.begin() + k;
        std::nth_element(workers.begin(), hiredEnd - 1, workers.end(), cmp_ratio_less);

        auto ratio = workers[k - 1];
        int qualitySum = 0;
        
        for (int i = k - 1; i >= 0; --i)
            qualitySum += workers[i] >> 16;
        std::make_heap(workers.begin(), hiredEnd);

        double total = qualitySum * as_ratio(ratio);
        std::sort(hiredEnd, workers.end(), cmp_ratio_less);
        for (auto it = hiredEnd; it != workers.end(); ++it) {
            ratio = *it;
            qualitySum += (*it >> 16) - (workers.front() >> 16);
            std::pop_heap(workers.begin(), hiredEnd);
            std::iter_swap(it, hiredEnd - 1);
            std::push_heap(workers.begin(), hiredEnd);
            total = std::min(total, qualitySum * as_ratio(ratio));
        }

        return total;
    }
};