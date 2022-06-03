class NumMatrix {
public:
    vector<vector<int>>abhi;
    
    NumMatrix(vector<vector<int>>& matrix) {
      for(int i=0;i<matrix.size();i++){
          vector<int>pre;
          int sum=0;
          for(int j=0;j<matrix[0].size();j++){
              sum+=matrix[i][j];
              pre.push_back(sum);
          }
          abhi.push_back(pre);
      }
        
    }
    
    int sumRegion(int row1, int col1, int row2, int col2) {
        int sum=0;
        for(int i=row1;i<=row2;i++){
            if(col1>0)sum+=abhi[i][col2]-abhi[i][col1-1];
            else sum+=abhi[i][col2];
        }
        return sum;
    }
};

/**
 * Your NumMatrix object will be instantiated and called as such:
 * NumMatrix* obj = new NumMatrix(matrix);
 * int param_1 = obj->sumRegion(row1,col1,row2,col2);
 */