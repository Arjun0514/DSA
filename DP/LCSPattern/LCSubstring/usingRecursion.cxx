class Solution {
  public:
    int longestCommonSubstr(string& s1, string& s2) {
        // your code here
        return longestCommonSubstrRec(s1, s2, s1.size(),s2.size(),0);
    }
    
    int longestCommonSubstrRec(string &s1,string &s2,int m,int n,int count){
        if(m==0||n==0)
          return count;
          
        int res=count;
        if(s1[m-1]==s2[n-1])
          res= longestCommonSubstrRec(s1,s2,m-1,n-1,count+1);
        else{
          return max({res,longestCommonSubstrRec(s1,s2,m-1,n,0),longestCommonSubstrRec(s1,s2,m,n-1,0)});
         }
    }
};
