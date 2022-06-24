class Solution {
    public List<Integer> getRow(int rowIndex) {
        List<List<Integer>>res=new ArrayList<List<Integer>>();
        for(int i=0;i<=rowIndex;i++){
            List<Integer>temp=new ArrayList<>();
            int j;
            for( j=0;j<=i;j++){
                if(j==0 || j==i){
                    temp.add(1);
                }
                else{
                    temp.add(res.get(i-1).get(j-1)+ res.get(i-1).get(j));
                }
            }
            if(j>rowIndex)return temp;
            res.add(temp);
        }
    return new ArrayList<Integer>();
    }
}