class Solution {
  public:
    int knapSack(vector<int>& val, vector<int>& wt, int capacity) {
        // code here
        vector<vector<int>> dp(wt.size()+1,vector<int>(capacity+1,0));
        for (int i=1;i<=wt.size();i++){
            for(int j=1;j<=capacity;j++){
                
                    int currentElement=wt[i-1];
                    int currentValue=val[i-1];
                    int pick=0;
                    if(currentElement<=j)
                       pick=currentValue+dp[i][j-currentElement];
                    int notPick=dp[i-1][j];
                    dp[i][j]= max(pick,notPick);
                
            }
        }
        return dp[wt.size()][capacity];
    }
};
