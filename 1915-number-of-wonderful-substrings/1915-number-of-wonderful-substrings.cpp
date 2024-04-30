class Solution {
public:
    long long wonderfulSubstrings(string word) {
       vector<int> count(1024, 0); 
        
        
        count[0] = 1; 
        int mask = 0;
        long long  ans = 0;
        
        for (char c : word) {
            int index = c - 'a'; 
            mask ^= 1 << index; 
            ans += count[mask]; 
            
            for (int i = 0; i < 10; i++) 
            { 
                int look = mask ^ (1 << i); 
                ans += count[look];
            }
            count[mask]++;
        }
        
        return ans;
    }
};