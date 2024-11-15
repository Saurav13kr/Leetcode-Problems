class Solution {
public:
    int findLengthOfShortestSubarray(vector<int>& arr) {
        int left = 0;
        for(int i = 0; i < arr.size()-1;i++){
            if(arr[i] <= arr[i + 1]){
                left = i + 1;
            } else{
                break;
            }
        }
        if(left == arr.size() - 1) return 0;
        int right = arr.size()-1;
        for(int i = arr.size()-1;i > left;i--){
            if(arr[i] >= arr[i - 1]){
                right = i - 1;
            }
            else{
                break;
            }
        }
        int n = arr.size();
        int result = min(n - left - 1, right);
        int i = 0, j = right;
        while (i <= left && j < n) {
            if (arr[i] <= arr[j]) {
                result = min(result, j - i - 1);
                i++;
            } else {
                j++;
            }
        }
        
        return result;
    }
};