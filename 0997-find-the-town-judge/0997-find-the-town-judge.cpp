class Solution {
public:
    int findJudge(int n, vector<vector<int>>& trust) {        
        vector<int> cnt1(n+1);  
        vector<int> cnt2(n+1); 

        for(vector<int>& t: trust){
            cnt1[t[0]]++;
            cnt2[t[1]]++;
        }

        for(int i=1; i<=n; i++){ 
            if(cnt1[i] == 0 && cnt2[i] == n-1){ 
                return i; 
            }
        }
        return -1;
    }
};