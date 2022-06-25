class Solution {
    public List<List<String>> partition(String s) {
        List<List<String>>res=new ArrayList<>();
        solve(0,s,res,new ArrayList<>());
        return res;
    }
    public void solve(int ind,String s,List<List<String>>res,List<String>temp){
        int n=s.length();
        if(ind>=n){
            res.add(new ArrayList<>(temp));
        }
        for(int i=ind;i<s.length();i++){
            if(isok(ind,i,s)){
                String t=s.substring(ind,i+1);
                temp.add(t);
                solve(i+1,s,res,temp);
                temp.remove(temp.size()-1);
            }
        }
    }
    public boolean isok(int start,int end,String s){
        while(start<=end){
            if(s.charAt(start)==s.charAt(end)){
                start++;
                end--;
            }else
                return false;
        }
        return true;
    }
}