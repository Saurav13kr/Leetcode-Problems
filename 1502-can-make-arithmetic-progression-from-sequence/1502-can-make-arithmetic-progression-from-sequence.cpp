class Solution {
public:
    bool canMakeArithmeticProgression(vector<int>& arr) {
        if(arr.size()==1 ||arr.size()==2){
            return true;
        }
        else{
            sort(arr.begin(),arr.end());
            int change = arr[0]-arr[1];
            for (size_t i = 0; i < arr.size()-1; i++) {
                if(arr[i]-arr[i+1]!=change){
                    return false;
                }
            }
            return true;
        }
    }
};