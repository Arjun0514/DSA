#include <iostream>
#include <vector>
#include <algorithm>
using namespace std;

int knapsack(vector<int> &wt, vector<int> &val, int cap){
        
    int n= wt.size();
    vector<int> dp(cap+1);
    
    for(int i=0;i<n; i++){
        int currentWeight= wt[i];
        int currentValue= val[i];
       for(int j=cap; j>=currentWeight; j--){
           dp[j]= max(dp[j],currentValue+ dp[j - currentWeight]);
       }
    } 
    return dp[cap];
}

int main(){
   vector<int> wt = {3,4,5,1,2};
   vector<int> val= {10,20,30,40,50};
   int cap=7;

   cout<<knapsack(wt,val,cap);
    
   return 0;
}
