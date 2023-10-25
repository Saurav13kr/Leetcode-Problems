class Solution {
public:
    int kthGrammar(int n, int k) {
        int p2[32], ptr = 0, cnt = 0;
        for(long long int i = 1; i <= INT_MAX; i <<= 1) 
            p2[ptr++] = i;

        function<int(int)> bs = [&] (int x) {
            int l = 0, r = 31;
            
            while(l <= r) {
                int mid = (l + r) >> 1;
                if(p2[mid] < x) {
                    l = mid + 1;
                }
                else {
                    r = mid - 1;
                }
            }
            return p2[r];
        };

        function<int(int)> rec = [&] (int x) -> int {
            if(x == 1 or x == 2) 
                return (x - 1);
            cnt++;
            return rec(x - bs(x));
        };

        int ans = rec(k);
        return (cnt & 1 ? ans ^ 1 : ans);
    }
};