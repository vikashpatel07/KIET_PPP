class Solution {
    public List<List<Integer>> combinationSum2(int[] can, int target) {
          Arrays.sort(can);
        List<List<Integer>>res=new ArrayList<>();
        solve(0,can,target,res,new ArrayList<>(),0);
        return res;
    }
    
    public void solve(int ind,int []can,int target,List<List<Integer>>res,List<Integer>temp,int sum){
       
            if(sum==target){
                res.add(new ArrayList<>(temp));
            }
        
       
        for(int i=ind;i<can.length;i++){
            if(i!=ind && can[i]==can[i-1])continue;
            if(sum+can[i]<=target){
                sum+=can[i];
                temp.add(can[i]);
                solve(i+1,can,target,res,temp,sum);
                sum-=can[i];
                temp.remove(temp.size()-1);
            }
        }
    }
    
}