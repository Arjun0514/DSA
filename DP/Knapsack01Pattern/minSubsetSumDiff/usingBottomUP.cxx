#include <iostream>
#include <vector>
#include <climits>
#include <algorithm>
using namespace std;

int minDiff(vector<int> &vec,int n,int subset1sum,int totalSum){
	
	vector<vector<bool>> dp(vec.size()+1,vector<bool>(totalSum+1,false));
	
	for(int i=0; i<=n; i++){
	    dp[i][0]=true;
	}

    for(int i=1;i<=vec.size();i++){
        for(int j=1;j<=totalSum;j++){
            int currentSum=vec[i-1];
            int pick=false;
            if(currentSum<=j)
              pick=dp[i-1][j-currentSum];
            
            int notPick=dp[i-1][j];
            dp[i][j]= (pick||notPick);
        }
    }
    
    int minDiff= INT_MAX;
    for(int i=0;i<=totalSum/2;i++){
        if(dp[n][i])
          minDiff= min(minDiff,abs((totalSum-i)-i));
    }
    return minDiff;
}

int main(){
	
vector<int> vec= {1,6,11,5};
  int totalSum=0;
  for(int i=0;i<vec.size();i++){
      totalSum=totalSum+vec[i];
  }
  int subset1=0;
  cout<<minDiff(vec,vec.size(),subset1,totalSum);
  return 0;
}
