class Solution {
public:
    vector<int> kthSmallestPrimeFraction(vector<int>& arr, int k) {
        int n = arr.size();
        double l = 0, h = 1.0; 

        while (l < h) {
            double mid = (l + h) / 2;
            vector<int> cnt = solve(arr, mid);

            if (k < cnt[0]) {
                h = mid;
            } 
            else if (k > cnt[0]) {
                l = mid;
            }
            else {
                return {cnt[1], cnt[2]};
            }
        }
        return {};
    }

    vector<int> solve(vector<int>& arr, double target) {
        int count = 0;
        int i = 0;
        int n = arr.size();
        int num = arr[0];
        int den = arr[n - 1];

        for (int j = 1; j < n; j++) {
            while (i < j && arr[i] <= arr[j] * target) { 
                i++;
            }
            count += i;  
            
            if (i > 0 && arr[i - 1] * den > arr[j] * num) {  
                num = arr[i - 1];
                den = arr[j];
            }
        }
        return {count, num, den};
    }
};