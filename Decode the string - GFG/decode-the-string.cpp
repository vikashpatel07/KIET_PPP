//{ Driver Code Starts
// Initial Template for C++

#include <bits/stdc++.h>
using namespace std;

// } Driver Code Ends
// User function Template for C++

class Solution{
public:
    string decodedString(string s){
        // code here
          stack<char>m;

        string ans="";

        for(int i=0;i<s.size();i++){

            if(s[i]==']'){

                while(m.top()!='['&&m.size()>0){

                    ans=m.top()+ans;

                    m.pop();

                }

                if(m.size()!=0)

                m.pop();

                

                string number="";

                while(m.size()!=0&&m.top()>='0'&&m.top()<='9'){

                    number=m.top()+number;

                    m.pop();

                }

                int digit=stoi(number);

                string temp=ans;

                for(int i=0;i<digit-1;i++)

                    ans+=temp;

                    

                 for(int i=0;i<ans.size();i++)

                 m.push(ans[i]);

                 ans="";

                 

                

            }

            else{

                m.push(s[i]);

            }

            

        }

       while(m.size()>0){

           ans=m.top()+ans;

           m.pop();

       }

       return ans;
    }
};

//{ Driver Code Starts.

int main(){
    int t;
    cin>>t;
    while(t--){
        string s;
        cin>>s;
        
        Solution ob;
        cout<<ob.decodedString(s)<<"\n";
    }
    return 0;
}
// } Driver Code Ends