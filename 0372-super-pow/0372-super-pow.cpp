class Solution {
public:
    int superPow(int a, vector<int>& b) {
        int exp = 0;
        int phi = 1140;
        
        for(auto it : b){
            exp = (exp*10 + it) % phi;
        }
        
        bitset<12> bs(exp);
        int power = a%1337, x = 1;
        cout << bs << endl;
        
        for(int i=0; i<12; i++){
            if(bs[i]) x = (x*power) % 1337;
            power = (power*power) % 1337;
        }
        return x;
    }
};