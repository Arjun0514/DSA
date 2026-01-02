// Online C++ compiler to run C++ program online
#include <iostream>
#include <vector>
#include <algorithm>
using namespace std;

int minDiff(vector<int> &vec, int totalSum,int currentSum,int n){
    vector<vector<int>> dp(n+1,vector<int>(totalSum+1,0));
    for(int i=0;i<=totalSum;i++){
        dp[0][i]=abs(totalSum-(2*i));
    }
    for(int i=1;i<=n;i++){
        for(int j=0;j<=totalSum;j++){
            int currentEle=vec[i-1];
            //pick
            int pick=0;
            if(currentEle+j<=totalSum)
               pick=dp[i-1][j+currentEle];
            
            int notPick=dp[i-1][j];
            dp[i][j]= min(pick,notPick);
        }
    }
    return dp[n][0];
}
int main() {
    // Write C++ code here
    vector<int> vec={1,6,11,5,3};
    int totalSum=0;
    int currentSum=0;
    for(int i=0;i<=vec.size();i++){
        totalSum=vec[i]+totalSum;
    }
    cout<<minDiff(vec,totalSum,currentSum,vec.size());
    return 0;
}
