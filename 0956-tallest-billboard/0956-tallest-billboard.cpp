class Solution {
    public:
		vector<unordered_map<int,int>> dp;
		int f(int i,vector<int>& v, int d){
			if(i==v.size()){
				if(d==0){
					return 0;
				}
			  return INT_MIN;
			}

			if(dp[i].find(d) != dp[i].end())
                return dp[i][d];
			int x = f(i+1,v,d);
			int y = v[i] + f(i+1,v,d+v[i]);
			int z = f(i+1,v,d-v[i]);
			return dp[i][d] = max({x,y,z});
		}
		int tallestBillboard(vector<int>& rods) {
			dp.assign(21,{});
			return f(0,rods,0);

		}
	};