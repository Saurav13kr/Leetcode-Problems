class Solution {
public:
    int rec(unordered_set<int>& se,int i,int last,int k,map<pair<int,int>,int>& mp){
        if(i==last){
            return 1;
        }

        if(i>last) 
            return 0;
        if(k==0) 
            return 0;
        if(!se.count(i)) 
            return 0;
        if(mp.count({i,k})) 
            return mp[{i,k}];

        if(rec(se,i+k-1,last,k-1,mp) || rec(se,i+k,last,k,mp) || rec(se,i+k+1,last,k+1,mp)){
            return mp[{i,k}] = 1;
        }
        return mp[{i,k}] = 0;
    }

    bool canCross(vector<int>& stones) {
        int n = stones.size();
        if(stones[1]!=1) 
            return false;
        unordered_set<int> se;
        
        for(int i=0;i<n;i++){
            se.insert(stones[i]);
        }
        
        map<pair<int,int>,int> mp;
        return rec(se,1,stones[n-1],1,mp);
    }
};