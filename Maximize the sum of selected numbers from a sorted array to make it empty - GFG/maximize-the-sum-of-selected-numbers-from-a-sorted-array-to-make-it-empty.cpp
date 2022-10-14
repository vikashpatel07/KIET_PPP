//{ Driver Code Starts
#include <bits/stdc++.h> 
using namespace std; 
  

// } Driver Code Ends
class Solution{
    public:
    int maximizeSum(int a[], int n) 
    {
        // Complete the function
          int ms=0;

        map<int,int,greater<int>> mp;

        for(int i=0;i<n;i++){

            mp[a[i]]++;

        }

        for(auto x:mp){

            if(mp.find(x.first-1)!=mp.end()&&mp[x.first]>0){

                mp[x.first-1]=mp[x.first-1]-mp[x.first];

            }

        }

        for(auto x:mp){

            if(x.second>0){

                ms=ms+(x.second)*(x.first);

            }

        }

        return ms;


    }

};


//{ Driver Code Starts.



int main()
{
    
    int t;cin>> t;
    while(t--)
    {
        int n;
        cin >> n;
        int arr[n];
        
        for(int i=0;i<n;i++)
            cin>>arr[i];
        sort(arr, arr+n);
        Solution ob;
        
        cout << ob.maximizeSum(arr, n) << endl;
        
        
    }

}


// } Driver Code Ends