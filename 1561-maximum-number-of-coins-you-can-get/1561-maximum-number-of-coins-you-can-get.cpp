class Solution {
public:
    int maxCoins(vector<int>& piles) {
        sort(piles.begin(),piles.end());
        int myCoin = 0;
        int n=piles.size();
        
        for(int i=n/3;i<n;i+=2){
            myCoin +=piles[i];
        }

        return myCoin;
    }
};