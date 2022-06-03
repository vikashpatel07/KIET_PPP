class NumMatrix {
public:
    vector<vector<int>>res;
    
    NumMatrix(vector<vector<int>>& matrix) {
        for(int i=0;i<matrix.size();i++)
        {
            vector<int>temp;
            int sum = 0;
            for(int j=0;j<matrix[0].size();j++)
            {
                sum+=matrix[i][j];
                temp.push_back(sum);
            }
            res.push_back(temp);
        }
    }
    
    int sumRegion(int row1, int col1, int row2, int col2) {
        int sum = 0;
        for(int i=row1;i<=row2;i++)
        {
            if(col1>0)
            {
                sum+=(res[i][col2]-res[i][col1-1]);
            }
            else
                sum+=res[i][col2];
        }
        return sum;
    }
};

/**
 * Your NumMatrix object will be instantiated and called as such:
 * NumMatrix* obj = new NumMatrix(matrix);
 * int param_1 = obj->sumRegion(row1,col1,row2,col2);
 */