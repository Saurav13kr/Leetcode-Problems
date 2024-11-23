class Solution {
public:
    vector<vector<char>> rotateTheBox(vector<vector<char>>& box) {
        int row = box[0].size(), column = box.size();
        vector<vector<char>> ans(row, vector<char>(column, '.'));
        
        for(int c=column-1;c>-1;c--)
        {
            int lowest = row-1;
            for(int r=row-1;r>-1;r--)
            {
                if(box[c][r]=='#'){
                    ans[lowest][column-1-c] = '#';
                    lowest-=1;
                }
                else if(box[c][r]=='*'){
                    ans[r][column-c-1]='*';
                    lowest = r-1;
                }
            }
        }
        return ans;
    }
};