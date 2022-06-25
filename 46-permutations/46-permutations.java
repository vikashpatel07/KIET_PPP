class Solution {
    public List<List<Integer>> permute(int[] nums) {
        int n=nums.length;
        List<List<Integer>>res=new ArrayList<>();
        int []vis=new int [n];
        List<Integer>temp=new ArrayList<>();
        solve(0,nums,res,temp,vis);
        return res;
    }
    public void solve(int ind,int[] nums,List<List<Integer>>res,List<Integer>temp,int []vis){
        if(temp.size()==nums.length){
            res.add(new ArrayList<>(temp));
        }
        for(int i=0;i<nums.length;i++){
            if(vis[i]==0){
                temp.add(nums[i]);
                vis[i]=1;
                solve(ind+1,nums,res,temp,vis);
                vis[i]=0;
                temp.remove(temp.size()-1);
            }
        }
    }
}