#include <iostream>
#include <vector>
using namespace std;

bool subSetSum(vector<int> &set, int target, int n){

     vector<vector<bool>> dp(set.size()+1,vector<bool>(target+1,false));
     
     for (int i = 0; i <= n; i++)
        dp[i][0] = true;
     
     for (int i=1;i<=n;i++){
         for(int j=1;j<=target;j++){
             int currentWeight=set[i-1];
             int pick=false;
             if(currentWeight<=j){
                 pick=dp[i-1][j-currentWeight];
             }
             int notPick=dp[i-1][j];
             dp[i][j]=pick||notPick;
         }
     }
     return dp[n][target];
}

int main(){
vector<int> set= {3,7,4,9,5};
int target=10;
if (subSetSum(set, target,set.size()))
        cout << "True" << endl;
    else
        cout << "False" << endl;

return 0;
}
