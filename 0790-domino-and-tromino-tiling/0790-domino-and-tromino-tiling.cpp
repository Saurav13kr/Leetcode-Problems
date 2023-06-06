class Solution {
public:
    int numTilings(int t) {
        if (t<3) return t;
        
        int modulo = pow(10,9) + 7;  
        vector<long> D(t+1,0), Tr(t+1,0);
        D[0] = 0,D[1] = 1, D[2] = 2;
        Tr[0] = 0, Tr[1] = 1, Tr[2] = 2;
        
        for (int j=3; j<=t; j++) {
            D[j] = (D[j-1] + D[j-2] + 2*Tr[j-2]) % modulo;
            Tr[j] = (Tr[j-1] + D[j-1]) % modulo;
        }
        
        return D[t];
    }
};