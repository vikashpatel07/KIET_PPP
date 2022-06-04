class Solution {
public:
    bool isvalid(int row,int col,vector<string> & temp,int n)
    {
        int dr=row;
        int dc=col;
        while(dr>=0 && dc>=0)
        {
            if(temp[dr][dc]=='Q')
                return false;
            dr--;
            dc--;
        }
           dr=row,dc=col;
        while(dr<n && dc>=0)
        {
            if(temp[dr][dc]=='Q')
                return false;
            dr++;
            dc--;
        }
        dr=row,dc=col;
        while(dc>=0)
        {
            if(temp[dr][dc]=='Q')
                return false;
            dc--;
        }
        return true;
    }
    void solve(int col,vector<vector<string>> & res,vector<string> & temp,int n)
    {
        if(col>=n)
        {
            res.push_back(temp);
            return;
        }
        for(int i=0;i<n;i++)
        {
            if(isvalid(i,col,temp,n))
            {
                temp[i][col]='Q';
                solve(col+1,res,temp,n);
                temp[i][col]='.';
            }
        }
    }
    vector<vector<string>> solveNQueens(int n) {
        vector<vector<string>>res;
        vector<string>temp;
        string s(n,'.');
        for(int i=0;i<n;i++)
            temp.push_back(s);
        solve(0,res,temp,n);
        return res;
    }
};