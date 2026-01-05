class Solution {
  public:
    int lcs(string &s1, string &s2) {
       
       vector<vector<int>> memo(s1.size()+1,vector<int>(s2.size()+1,-1));
       return lcsRec(s1,s2,s1.size(),s2.size(),memo);
        
    }
    
    int lcsRec(string &s1,string &s2, int m, int n,vector<vector<int>> &memo){
       if(m==0||n==0)
          return 0;
          
       if(memo[m][n]!=-1)
          return memo[m][n];
       
       if(s1[m-1]== s2[n-1]){
          return memo[m][n]=1+lcsRec(s1,s2,m-1,n-1,memo);
       }
       else{
           return memo[m][n]=max(lcsRec(s1,s2,m,n-1,memo),lcsRec(s1,s2,m-1,n,memo));
       }
    }
};
