class Solution {
public:
    int countStudents(vector<int>& students, vector<int>& sandwiches) {
        unordered_map<int,int>mp;

        for(int i=0;i<students.size();i++){
            mp[students[i]]++;
        }
        int i=0;
        for( i=0;i<sandwiches.size();i++){
            
            if(mp[sandwiches[i]]>=1)
            mp[sandwiches[i]]--;
            else
            return sandwiches.size()-i;
        }
        return 0;


    }
};