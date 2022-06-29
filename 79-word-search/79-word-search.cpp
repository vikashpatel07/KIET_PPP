class Solution {
public:
   bool dfs(int ind,int row,int col,vector<vector<char>>&board,string& word){
       if(ind>=word.length())return true;
       if(row<0 || row>=board.size() || col<0 || col>=board[0].size() || board[row][col]=='.')
           return false;
       if(board[row][col]!=word[ind])
           return false;
       char temp=board[row][col];
       board[row][col]='.';
       if(dfs(ind+1,row+1,col,board,word) || dfs(ind+1,row,col+1,board,word) || dfs(ind+1,row,col-1,board,word) || dfs(ind+1,row-1,col,board,word))
           return true;
       board[row][col]=temp;
       return false;
   }
    bool exist(vector<vector<char>>& board, string word) {
        for(int i=0;i<board.size();i++){
            for(int j=0;j<board[0].size();j++){
                if(dfs(0,i,j,board,word)){
                    return true;
                }
            }
        }
        return false;
    }
};