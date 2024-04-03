class Solution {
public:
    int dr[4] = {-1,0,+1,0};
    int dc[4] = {0,+1,0,-1};
    int n,m;
    bool check(int sr,int sc,vector<vector<char>>& board, string &word,vector<vector<bool>>& vis,int ind){
        vis[sr][sc]=true;
        if(ind == word.size())return true;
        for(int i=0;i<4;i++){
            int nr = sr+dr[i];
            int nc = sc+dc[i];
            if(nr>=0 && nc>=0 && nr<n&& nc<m && !vis[nr][nc]){
                if(word[ind]==board[nr][nc]){
                    if(check(nr,nc,board,word,vis,ind+1)){
                        vis[sr][sc] = false;
                        return true;
                    }
                }
            }
        }
        vis[sr][sc] = false;
        return false;
        
    }
    bool exist(vector<vector<char>>& board, string word) {
        n = board.size();
        m = board[0].size();
        vector<vector<bool>>vis(n,vector<bool>(m,0));
        for(int i=0;i<n;i++){
            for(int j=0;j<m;j++){
                if(board[i][j]==word[0]){
                    if(check(i,j,board,word,vis,1)){
                        return true;
                    }
                }
            }
        }
        return false;
    }
};