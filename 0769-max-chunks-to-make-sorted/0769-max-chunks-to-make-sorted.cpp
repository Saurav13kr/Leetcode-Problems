class Solution {
public:
    int maxChunksToSorted(vector<int>& arr) {
	int res = 0, n = arr.size();
	for (int i = 0, sum = 0, isum = 0; i < n; i++) {
		isum += i;
		sum += arr[i];
		if (isum == sum)
			res++;
	}
	return res;
}
};