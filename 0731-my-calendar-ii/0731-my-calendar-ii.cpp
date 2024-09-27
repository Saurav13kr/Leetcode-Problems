class MyCalendarTwo {
private:
    vector<pair<int, int>> bookings;   // Stores all valid bookings
    vector<pair<int, int>> overlaps;   // Stores intervals where bookings overlap twice

public:
    MyCalendarTwo() {
        // No initialization needed
    }
    
    bool book(int start, int end) 
    {
        for (auto& [ov_start, ov_end] : overlaps) {
            if (start < ov_end && end > ov_start) {
                return false;  // If it overlaps with a double booking, it's invalid
            }
        }

        for (auto& [book_start, book_end] : bookings) {
            if (start < book_end && end > book_start) {
                // Calculate the overlapping interval
                int ov_start = max(start, book_start);
                int ov_end = min(end, book_end);
                overlaps.push_back({ov_start, ov_end});
            }
        }

        bookings.push_back({start, end});
        return true;
    }
};