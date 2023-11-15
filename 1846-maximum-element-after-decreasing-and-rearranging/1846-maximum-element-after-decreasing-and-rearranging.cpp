class Solution {

public:
    int maximumElementAfterDecrementingAndRearranging(vector<int>& arr) {
        sort(arr.begin(),arr.end());
        int k=1;
        for(int i=1;i<arr.size();i++) {
            if(arr[i]==arr[i-1] && arr[i]>k)
            k++;
            if(arr[i]>arr[i-1])
            k++;
        }
        return k;
    }
};