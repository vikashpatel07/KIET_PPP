class Solution {
public:
    bool issafe(int row,int col,vector<string> & board,int n)
    {
        int dr=row,dc=col;
        while(dc>=0 && dr>=0)
        {
            if(board[dr][dc]=='Q')
                return false;
            dc--;
            dr--;
        }
        dc=col,dr=row;
        while(dc>=0 && dr<n)
        {
             if(board[dr][dc]=='Q')
                return false;
            dc--;
            dr++;
        }
         dc=col,dr=row;
        for(int i=0;i<n;i++)
        {
            if(board[row][i]=='Q')
                return false;
        }
         for(int i=0;i<n;i++)
        {
            if(board[i][col]=='Q')
                return false;
        }
        return true;
        
        
    }
    void solve(int col,vector<vector<string>> & res,vector<string> & board,int n)
    {
        if(col==n)
        {
            res.push_back(board);
        }
       for(int row=0;row<n;row++)
       {
           if(issafe(row,col,board,n))
           {
               board[row][col]='Q';
               solve(col+1,res,board,n);
               board[row][col]='.';
           }
       }
    }
      int totalNQueens(int n) {
        vector<vector<string>>res;
        vector<string>board(n);
        string s(n,'.');
        for(int i=0;i<n;i++)
        {
            board[i]=s;
        }
        solve(0,res,board,n);
        return res.size();
  
        
    }
};