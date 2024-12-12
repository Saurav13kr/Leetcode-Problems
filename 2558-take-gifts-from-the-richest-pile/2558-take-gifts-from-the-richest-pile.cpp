class Solution {
    public:
        long long pickGifts(vector<int> &gifts, int k) {
            priority_queue<int, vector < int>> pq;
            for (int num: gifts)
            {
                pq.push(num);
            }
            int cnt = 0;
            while (!pq.empty() && cnt< k) {
                int gift = pq.top();
                cnt++;
                pq.pop();
                pq.push((int) sqrt(gift));
            }
            long long rem = 0;
            while (!pq.empty()) {
                int gift = pq.top();
                pq.pop();
                rem += gift;
            }
            return rem;
        }
};