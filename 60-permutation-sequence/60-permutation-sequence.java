class Solution {
    public String getPermutation(int n, int k) {
        List<Integer>temp=new ArrayList<>();
        int fact=1;
        for(int i=1;i<=n;i++){
            temp.add(i);
            if(i==n)continue;
            fact*=i;
        }
        k--;
        String res="";
        while(true){
            
            int t=k/fact;
            res+=temp.get(t);
            
            temp.remove(t);
            if(temp.size()==0)break;
            k=k%fact;
            fact=fact/temp.size();
            
        }
        return res;
        
    }
}