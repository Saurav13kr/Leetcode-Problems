class Solution {
public:
    bool canPlaceFlowers(vector<int>& fb, int n) {
        if (n == 0) return true;
        
        for (int i = 0; i < fb.size(); i++) {
            if(fb[i]==0&&(i==0||fb[i-1]==0)&&(i==fb.size()-1||fb[i + 1] == 0)) { 
                -- n;
                if (n == 0) return true;
                fb[i] = 1; 
            }
        }
        return false;
    }
};