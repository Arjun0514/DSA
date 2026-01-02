class Solution {
  public:
    int knapsackRec(vector<int>& val, vector<int>& wt, int capacity,int n){
        if(capacity==0 || n==0)
           return 0;
        
        int pick=0;
        if(wt[n-1]<=capacity)
           pick=val[n-1]+knapsackRec(val,wt,capacity-wt[n-1],n);
        
        int notPick=knapsackRec(val,wt,capacity,n-1);
        return max(pick,notPick);
    }
  
    int knapSack(vector<int>& val, vector<int>& wt, int capacity) {
        // code here
        
        return knapsackRec(val,wt,capacity,wt.size());
    }
};
