class Solution {
public:
    int singleNumber(vector<int>& nos) 
{ 
       int c=0;
        
	   for(auto s:nos)
	   c^=s;
	   return c;
    }
};
