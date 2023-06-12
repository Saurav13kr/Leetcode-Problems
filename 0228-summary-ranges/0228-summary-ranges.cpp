class Solution {
public:
    vector<string> summaryRanges(vector<int>& arr) {
        int n = arr.size(); 
        vector<string> c;  
        string temp = ""; 
        
        for(int a=0; a<n; a++) {
            int b = a; 
            while(b+1 < n && arr[b + 1] == arr[b] + 1) {
                b++;
            }

            if(b > a) {
                temp += to_string(arr[a]); 
                temp += "->";
                temp += to_string(arr[b]); 
            } 
            
            else {
                temp += to_string(arr[a]); 
            }  
            c.push_back(temp);
            temp = ""; 
            a = b;
        }
        
        return c; 
    }
};