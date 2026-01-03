class Solution {
public:
    

    int coinChnageRec(vector<int> &coins,int amount,int n){
         if(amount==0){
            return 0;
         }
         if(n==0){
            return INT_MAX-1;
         }
        
         int pick=INT_MAX;
         if(coins[n-1]<=amount){
            pick=1+coinChnageRec(coins, amount-coins[n-1], n);
         }
         int notPick=coinChnageRec(coins,amount,n-1);
         return min(pick,notPick);
    }
    
    int coinChange(vector<int>& coins, int amount) {
        
        int ans=coinChnageRec(coins,amount,coins.size());
        if (ans==INT_MAX-1)
           return -1;
        else
           return ans; 
    }   
};
