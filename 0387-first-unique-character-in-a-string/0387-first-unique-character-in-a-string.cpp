static const void __attribute__((constructor)) fast()
{
    ios_base::sync_with_stdio(false);
    cin.tie(nullptr);
}

class Solution {
public:
    int firstUniqChar(const string& s) {
        for(size_t i = 0; i < s.size(); ++i){
            size_t j = 0;

            while(j < s.size())
            {
                if(s[i] == s[j] && j != i) break;
                
                ++j;
            }
                
            if(j == s.size()) return i;
        }

        return -1;
    }
};