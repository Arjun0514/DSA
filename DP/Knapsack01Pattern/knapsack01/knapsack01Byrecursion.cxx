#include <iostream>
#include <vector>
#include <string>
#include <algorithm>
using namespace std;

int knapsack(vector<int>&wt, vector<int>&val, int n,int cap)
{
   if(n==0 || cap==0){
     return 0;
   }
   int pick=0;
   if(wt[n-1]<=cap){
      pick = val[n-1] + knapsack(wt, val,n-1, cap-wt[n-1]);
   }
   int notpick=knapsack(wt,val,n-1,cap);
   return max(pick,notpick);
}

int main()
{
  vector<int> wt = {8,2,4,3,1,5};
  vector<int> val= {10,4,2,5,7,4};
  int n= wt.size();
  int cap= 7;
  int ans=knapsack(wt,val,n,cap);
  cout<<ans;
  return 0;
}
