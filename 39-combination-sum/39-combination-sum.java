class Solution {
    public List<List<Integer>> combinationSum(int[] can, int target) {
        Arrays.sort(can);
        List<List<Integer>>res=new ArrayList<>();
        solve(0,can,target,res,new ArrayList<>(),0);
        return res;
    }
    
    public void solve(int ind,int []can,int target,List<List<Integer>>res,List<Integer>temp,int sum){
        if(ind>=can.length){
            if(sum==target){
                res.add(new ArrayList<>(temp));
            }
            return;
        }
        if(can[ind]+sum<=target){
            sum+=can[ind];
            temp.add(can[ind]);
            solve(ind,can,target,res,temp,sum);
            temp.remove(temp.size()-1);
            sum-=can[ind];
        }
        solve(ind+1,can,target,res,temp,sum);
    }
}