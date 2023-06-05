class Solution {
public:
    bool checkStraightLine(vector<vector<int>>& coordinates) {
        int ab = coordinates.size();
        if (ab == 1) return false; 
        if (ab == 2) return true;  
        int s = coordinates[0][0], m = coordinates[0][1];
        int dx = coordinates[1][0] - s, dy = coordinates[1][1] - m;
        
        for (int i = 1; i < ab; i++) {   
            int x = coordinates[i][0], y = coordinates[i][1];
            if (dx * (y - m) != dy * (x - s))  
			    return false;
        }
        return true;
    }
};