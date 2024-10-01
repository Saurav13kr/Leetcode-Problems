class Solution {
public:
     bool canArrange(vector<int>& arr, int k) {
        
        vector<int> count(k,0);
        
        for(auto u : arr)
        {
            count[(k+u%k)%k]++;
        }
        
        if(k%2 == 0 && count[k/2]%2 == 1)
            return false;
         
        if(count[0]%2 == 1) 
            return false;
        
        int i=1,j=k-1;
        while(i < j){
            if(count[i] != count[j]) 
                return false;
            i++;
            j--;
        }
        return true;
		}
};