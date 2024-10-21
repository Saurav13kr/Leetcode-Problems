class Solution {
    void allPossibleSubstrings(string& s,int pos,int& maxcount,unordered_set<string>& unique){
        if(pos==s.size())
        {
            if(maxcount < unique.size())
                maxcount = unique.size();
            return;
        }
        string substring; 
        for(int i=pos;i<s.size();++i)
        {
            substring.push_back(s[i]);

            if(unique.count(substring)==0){
                unique.insert(substring);
                allPossibleSubstrings(s,i+1,maxcount,unique);
                unique.erase(substring);
            }
        }
    }
public:
    int maxUniqueSplit(string s) 
    {
        int maxcount=0;
        unordered_set<string> unique;
        allPossibleSubstrings(s,0,maxcount,unique);
        return maxcount;
    }
};