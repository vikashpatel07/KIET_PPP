class Solution {
    public void rotate(int[][] matrix) {
        for(int i=0;i<matrix.length;i++){
            for(int j=i;j<matrix[0].length;j++){
                int temp=matrix[i][j];
                matrix[i][j]=matrix[j][i];
                matrix[j][i]=temp;
                System.out.print(matrix[i][j]+" ");
            }
            System.out.print("\n");
        }
        
        for(int i=0;i<matrix.length;i++){
            int n=matrix[0].length;
            int []temp=new int[n];
            for(int j=0;j<n;j++){
                temp[n-1-j]=matrix[i][j];
                // n--;
        }
            for(int j=0;j<matrix[0].length;j++)matrix[i][j]=temp[j];
    }
    }
}