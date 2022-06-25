class Solution {
    public List<List<Integer>> subsetsWithDup(int[] nums) {
        Arrays.sort(nums);
        List<List<Integer>>res=new ArrayList<>();
        solve(0,nums,res,new ArrayList<>());
        return res;
    }
    
    public void solve(int ind,int []nums,List<List<Integer>>res,List<Integer>temp){
        res.add(new ArrayList<>(temp));
        for(int i=ind;i<nums.length;i++){
            if(i!=ind && nums[i]==nums[i-1])continue;
            temp.add(nums[i]);
            solve(i+1,nums,res,temp);
            temp.remove(temp.size()-1);
        }
    }
}