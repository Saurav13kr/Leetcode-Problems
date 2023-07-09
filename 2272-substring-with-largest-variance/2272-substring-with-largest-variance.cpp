class Solution {
public:
   int largestVariance(string s) {
    int c = 0;
    unordered_set<char> unique(begin(s), end(s));
       
    for (char a : unique)
        for (char b:unique) {
            int var = 0, z = 0, x = 0;
            
            for (auto ch:s) {
                var += ch == a;
                
                if (ch == b) {
                    z = true;
                    
                    if (x && var >= 0)
                        x = false;
                    
                    else if (--var < 0) {
                        x = true;
                        var = -1;
                    }
                }
                
                c = max(c, z ? var : 0);
            }
        }
       
    return c;
}};