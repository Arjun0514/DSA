class Solution {
  public:
  
    int count(vector<int>& coins, int sum) {
        // code here.
        int n =coins.size();
        vector<vector<int>> dp(coins.size()+1,vector<int>(sum+1,0));
        
        for(int i=0;i<=n;i++){
            dp[i][0]=1;
        }
        
        for(int i=1;i<=n;i++){
            for(int j=1;j<=sum;j++){
                int currentCoin=coins[i-1];
                int pick=0;
                if(currentCoin<=j)
                    pick=dp[i][j-currentCoin];
                int notPick=dp[i-1][j];
                dp[i][j]=pick+notPick;
            }
        }
        return dp[n][sum];
    }
};
