class Solution {
public:
    int leastInterval(vector<char>& tasks, int n) {
        int count[26] = {0};
        for(char ele : tasks){
            count[ele-'A']++;
        }
        sort(count , count+26);
        int num = count[25]-1;
        int temp = num*n;

        for(int i=24; i>=0; i--){
            temp -= min(num , count[i]);
        }
        return temp<0 ? tasks.size() : tasks.size()+temp;
    }
};