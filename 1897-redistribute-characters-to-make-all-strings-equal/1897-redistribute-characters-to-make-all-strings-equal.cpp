class Solution {
public:
    bool makeEqual(vector<string>& words) {
        unordered_map<char,int> m;

        for(int i=0; i<words.size(); i++){
            string s = words[i];

            for(char ch : s) m[ch]++;
        }

        int totalWords = words.size();

       for(auto it : m){
           int num = it.second;
           if(num % totalWords != 0) 
               return false;
       }

        return true;
    }
};