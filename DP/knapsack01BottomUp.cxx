#include <iostream>
#include <vector>
using namespace std;

int knapsack(vector<int> &wt, vector<int> &val, int cap){
        
    int n= wt.size();
    vector<vector<int>> dp(n+1, vector<int>(cap+1,0));
    
    for(int i=1;i<=n; i++){
       for(int j=1; j<=cap; j++){
          int currentWeight= wt[i-1];
          int currentValue= val[i-1];

          if(currentWeight<=j){
             dp[i][j] = currentValue+ dp[i-1][j-currentWeight];
          }
          else{
             dp[i][j] = dp[i-1][j];
          }
       }
    } 
    return dp[n][cap];
}

int main(){
   vector<int> wt = {3,4,5,1,2};
   vector<int> val= {10,20,30,40,50};
   int cap=7;

   cout<<knapsack(wt,val,cap);
    
   return 0;
}
