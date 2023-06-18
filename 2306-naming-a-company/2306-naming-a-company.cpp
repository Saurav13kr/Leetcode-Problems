class Solution {
public:
    long long distinctNames(vector<string>& ideas) {        
        long long c = 0;
        unordered_set<string> suffixes[26];

        for(auto idea : ideas) {
            suffixes[idea[0] - 'a'].insert(idea.substr(1));
        }
        
        for(int i=0; i<25; i++) {
            
            for(int j=i+1; j<26; j++) {
                int count=0;

                for(auto suffix : suffixes[i]) {
                    if(suffixes[j].count(suffix)) {
                        count++;
                    }
                }
                c = c + (2 * (suffixes[i].size()-count) * (suffixes[j].size()-count));
            }
        }
        
        return c;
    }
};
