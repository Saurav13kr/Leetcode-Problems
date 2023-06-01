/**
 * Your RecentCounter object will be instantiated and called as such:
 * RecentCounter* obj = new RecentCounter();
 * int param_1 = obj->ping(t);
 */

class RecentCounter {
public:
    RecentCounter() {}
    int ping(int t) {
        calls.push_back(t);
        while (calls[0] < t - 3000)
            calls.erase(calls.begin());
        return calls.size();
    }
    
private:
    vector<int> calls;
};