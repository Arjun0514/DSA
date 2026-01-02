class Solution {
  public:
  
    int countRec(vector<int> &coins,int sum,int n){
        if(sum==0){
            return 1;
        }
        if(n==0){
            return 0;
        }
        
        int pick=0;
        if(coins[n-1]<=sum)
           pick=countRec(coins,sum-coins[n-1],n);
        
        int notPick=countRec(coins,sum,n-1);
        
        return (pick+notPick);
           
        
    }
    int count(vector<int>& coins, int sum) {
        // code here.
        int n =coins.size();
        return countRec(coins,sum,n);
    }
};
