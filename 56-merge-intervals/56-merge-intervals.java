class Solution {
  
    public int[][] merge(int[][] intervals) {
        int []temp=new int[2];
        List<int []>res=new ArrayList<int[]>();
        Arrays.sort(intervals,(a,b)->a[0]-b[0]);
        temp[0]=intervals[0][0];
        temp[1]=intervals[0][1];
        for(int i=1;i<intervals.length;i++){
            if(intervals[i][0]<=temp[1]){
                temp[1]=Math.max(intervals[i][1],temp[1]);
            }
            else{
                res.add(temp);
                temp=intervals[i];
            }
        }
        res.add(temp);
        return res.toArray(new int[res.size()][]);
    }
}