class Solution {
public:
	char nextGreatestLetter(vector<char>& letters, char target) {
		int mid, s = 0, r = letters.size() - 1;
        
		while(s < r) {
			mid = (s + r) / 2;
			if(letters[mid] <= target){
				s = mid + 1;
			} else{
				r = mid;
			}
		}
        
		if(letters[s] > target){
			return letters[s];
		}
		return letters[0];
	}
};