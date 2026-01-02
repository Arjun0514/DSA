class Solution {
  public:
    int knapsackRec(vector<int>& val, vector<int>& wt, int capacity,int n,vector<vector<int>>&memo){
        if(capacity==0 || n==0)
           return 0;
        
        if(memo[n][capacity]!=-1)
           return memo[n][capacity];
        int pick=0;
        if(wt[n-1]<=capacity)
           pick=val[n-1]+knapsackRec(val,wt,capacity-wt[n-1],n,memo);
        
        int notPick=knapsackRec(val,wt,capacity,n-1,memo);
        return memo[n][capacity]=max(pick,notPick);
    }
  
    int knapSack(vector<int>& val, vector<int>& wt, int capacity) {
        // code here
        vector<vector<int>>memo(wt.size()+1,vector<int>(capacity+1,-1));
        return knapsackRec(val,wt,capacity,wt.size(),memo);
    }
};
