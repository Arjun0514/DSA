#include <iostream>
#include <vector>
using namespace std;

int countSum(vector<int> &vec, int target,int n,int currentSum){
    
    vector<vector<int>> dp(vec.size()+1,vector<int>(target+1,0));
    for(int i=0;i<=n;i++){
       dp[i][0]=1;
    }
    
    for(int i=1;i<=vec.size();i++){
        for(int j=1;j<=target;j++){
            int currentEle=vec[i-1];
            int pick=0;
            if(currentEle<=j){
                pick=dp[i-1][j-currentEle];
            }
            int notPick= dp[i-1][j];
            dp[i][j]=pick+notPick;
        }
    }
    return dp[n][target];
}

int main(){
vector<int> vec={3,7,4,6,3};
int target=10;
int sum=0;
cout<<countSum(vec,target,vec.size(),sum);

return 0;
}
