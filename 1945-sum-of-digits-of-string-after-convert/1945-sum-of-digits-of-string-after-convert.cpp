class Solution {
public:
    int getLucky(string s, int k) {
        ios_base::sync_with_stdio(false);
        long long sum = 0, res = 0;
        for (int i = 0; i < s.size(); i++) {
            int x=s[i]-'a'+1;
            if(x>=10)
            {
                sum+=x/10;
                sum+=x%10;
                continue;
            }
            sum+=x;
        }
        k--;
        while (k--) {
            res = 0;
            while (sum > 0)
            {
                res += sum % 10;
                sum /= 10;
            }
            if (res <= 9)
                return res;
            swap(res, sum);
        }
        return sum;
    }
};