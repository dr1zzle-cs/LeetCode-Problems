//{ Driver Code Starts
#include<bits/stdc++.h>
using namespace std;

// } Driver Code Ends
class Solution
{
    public:
    //Function to find minimum number of attempts needed in 
    //order to find the critical floor.
    
    int dp[205][205];
    
    int sol(int n, int k){
        if(n == 1 or k==0 or k==1){
            return k;
        }
        
        int ans = INT_MAX;
        
        if(dp[n][k] != -1) return dp[n][k];
        
        for(int i = 1; i<=k; i++){
            int c1 = sol(n-1, i-1); //egg breaks
            int c2 = sol(n, k-i); //egg does not break
            int worst = 1+ max(c1, c2);
            ans = min(ans, worst);
        }
        
        dp[n][k] = ans;
        return dp[n][k];
    }
    
    int eggDrop(int n, int k) 
    {
        memset(dp, -1, sizeof(dp));
        return sol(n, k);
    }
};

//{ Driver Code Starts.
int main()
{
    //taking total testcases
    int t;
    cin>>t;
    while(t--)
    {
        //taking eggs and floors count
        int n, k;
        cin>>n>>k;
        Solution ob;
        //calling function eggDrop()
        cout<<ob.eggDrop(n, k)<<endl;
    }
    return 0;
}

// } Driver Code Ends