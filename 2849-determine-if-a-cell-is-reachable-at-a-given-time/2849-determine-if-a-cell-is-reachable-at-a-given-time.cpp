class Solution {
public:
    bool isReachableAtTime(int sx, int sy, int fx, int fy, int t) {
        if(sx == fx && sy == fy){
            if(t==1){
                return false;
            }
            return true;
        }

        int Dx = abs(sx-fx);
        int Dy = abs(sy-fy);

        if(max(Dx,Dy) > t){
            return false;
        }

        return true;
    }
};