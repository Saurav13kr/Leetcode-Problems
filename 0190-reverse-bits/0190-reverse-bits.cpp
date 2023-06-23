class Solution {
public:
    uint32_t reverseBits(uint32_t n) {
        uint32_t c = 0;
        
        for (int i = 0; i < 32; i++) {
            c <<= 1;
            c += n % 2;
            n >>= 1;
        }
        
        return c;
    }
};