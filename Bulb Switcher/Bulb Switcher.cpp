class Solution {
public:
    int bulbSwitch(int s) {
        long long i = 1;

        int aj = 0;

        while((i * i) <= s) {
            i++;
            aj++;
        }

        return aj;
    }
};
