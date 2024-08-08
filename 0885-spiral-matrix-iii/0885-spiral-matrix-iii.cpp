class Solution {
public:
    vector<vector<int>> spiralMatrixIII(int rows, int cols, int r, int c) {
        int cnt = 1;
        vector<vector<int>>v;
        v.push_back({r,c});
        while(v.size()<rows*cols)
        {
            for(int i = 0 ;i<cnt;i++)
            {
                c++;
                if(r<rows&&r>=0&&c<cols&&c>=0)
                    v.push_back({r,c});
            }
            for(int i = 0 ;i<cnt ;i++)
            {
                r++;
                if(r<rows&&r>=0&&c<cols&&c>=0)
                    v.push_back({r,c});
            }
            cnt++;
            for(int i = 0 ;i<cnt;i++)
            {
                c--;
                if(r<rows&&r>=0&&c<cols&&c>=0)
                    v.push_back({r,c});
            }
            for(int i = 0 ;i<cnt ;i++)
            {
                r--;
                if(r<rows&&r>=0&&c<cols&&c>=0)
                    v.push_back({r,c});
            }
            cnt++;
        }
        return v;
    }
};