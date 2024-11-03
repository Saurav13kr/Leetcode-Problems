class Solution {
public:
    bool rotateString(string s, string goal) {

        int n=s.size();
        for(int i=0;i<n;i++)
        {
            if(s==goal)return true;
            char ch=s.back();
            s.pop_back();
            s.insert(s.begin(),ch);
        }

        return false;  
    }
};