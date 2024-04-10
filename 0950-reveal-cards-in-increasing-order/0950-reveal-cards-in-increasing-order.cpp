class Solution {
public:
    vector<int> deckRevealedIncreasing(vector<int>& deck) {
        sort(deck.rbegin(),deck.rend());
        vector<int> ar;
        ar.push_back(deck[0]);
        int n = deck.size();
        
        for(int i=1;i<n;i++)
        {
            int a = ar.back();
            ar.pop_back();
            ar.insert(ar.begin(),a);
            ar.insert(ar.begin(),deck[i]);
        }
        return ar;
    }
};