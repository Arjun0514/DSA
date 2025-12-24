#include <iostream>
#include <vector>
#include <string>
#include <algorithm>
using namespace std;

int knapsack(vector<int>&wt, vector<int>&val, int n,int cap,vector<vector<int>> &memo)
{
   if(n==0 || cap==0){
     return 0;
   }

   if(memo[n][cap]!=-1){
       return memo[n][cap];
   }
   int pick=0;
   if(wt[n-1]<=cap){
      pick = val[n-1] + knapsack(wt, val,n-1, cap-wt[n-1],memo);
   }
   int notpick=knapsack(wt,val,n-1,cap,memo);
   return memo[n][cap]=max(pick,notpick);
}

int main()
{
  vector<int> wt = {8,2,4,3,1,5};
  vector<int> val= {10,4,2,5,7,4};
  int n= wt.size();
  int cap= 7;
  
  vector<vector<int>> memo{wt.size()+1,vector<int>(cap+1,-1)};
  int ans=knapsack(wt,val,n,cap,memo);
  cout<<ans;
  
  return 0;
}
