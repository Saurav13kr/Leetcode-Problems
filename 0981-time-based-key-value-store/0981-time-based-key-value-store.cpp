class TimeMap {
public:
    unordered_map<string,vector<pair<int,string>>>mp;
    TimeMap() {    
    }
    void set(string key, string value, int timestamp) {
        mp[key].push_back({timestamp,value});
    }
    
    pair<int,string> searchEqualOrLesser(vector<pair<int, string>>&arr, int key) {
        int n = arr.size();
        int low = 0, high = n-1, res = INT_MAX;
        
        while(low <= high){
            int mid = low + (high - low)/2;
            if(arr[mid].first < key){
                res = mid;
                low = mid+1;
            }
            else if(arr[mid].first > key){
                high = mid - 1;
            }
            else
            {
                res = mid;
                break;
            }
        }
        if(res == INT_MAX){
            return {INT_MAX,""};
        }
        return arr[res];
    }
    
    string get(string key, int timestamp) {
        pair<int,string> p = searchEqualOrLesser(mp[key],timestamp);
        if(p.first == INT_MAX){
            return "";
        }
        return p.second;
    }
};