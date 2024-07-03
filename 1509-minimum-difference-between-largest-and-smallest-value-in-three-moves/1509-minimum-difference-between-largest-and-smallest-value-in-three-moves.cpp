class Solution {
int n;
vector<int> v;

private:
    int ex(int i, int j, int count)
    {
        if(!count) return v[j]-v[i];

        return min(ex(i+1,j,count-1),ex(i,j-1,count-1)); 
    }

public:
    int minDifference(vector<int>& nums) {
        if(nums.size()<=4) return 0;
        this->v=nums;
        this->n=nums.size();
        sort(v.begin(),v.end());

        return ex(0,n-1,3);
    }
};