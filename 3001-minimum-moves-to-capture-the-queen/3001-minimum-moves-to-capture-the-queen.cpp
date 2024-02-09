class Solution {
public:
    int minMovesToCaptureTheQueen(int a, int b, int c, int d, int e, int f) {
        int ans=2;
        if((a==e && !(c==e && (d-b)*(d-f)<0)) || (b==f && !(d==f && (c-a)*(c-e)<0))) return 1;
        if(abs(c-e)==abs(d-f)){
            bool maybe=true;
            int d1=(e>c)?1:(-1);
            int d2=(f>d)?1:(-1);

            for(;!(c==e && d==f);c+=d1,d+=d2){
                if(c==a && d==b){
                    maybe=false;
                    break;
                }
            }
            if(maybe) return 1;
        }
        return 2;
    }
};