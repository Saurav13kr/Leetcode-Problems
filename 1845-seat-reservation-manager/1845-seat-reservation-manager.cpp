class SeatManager {
public:
    priority_queue<int, vector<int>, greater<int>> pq ; 
    int cnt =0 ; 
    SeatManager(int n) {
        cnt=1; 
    }  
    int reserve() {
        if (pq.empty()) return cnt++; 
        int res= pq.top(); 
        pq.pop(); 
        return res;  
    }
    
    void unreserve(int seatNumber) {
        pq.push(seatNumber); 
    }
};

/**
 * Your SeatManager object will be instantiated and called as such:
 * SeatManager* obj = new SeatManager(n);
 * int param_1 = obj->reserve();
 * obj->unreserve(seatNumber);
 */