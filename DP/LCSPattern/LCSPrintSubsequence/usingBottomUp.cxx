/*Printing LCSubsequence
s1=ABCDGH
s2=AEDFHR

solution:-
I know recursive approach for finding count of LC subsequence and LC substring
-base case if any string becomes empty return str
-if m and n matches then 1+rec(m-1,n-1) return str.push_back(s1[m-1]) 
-or call max((m-1,n),(m,n-1))

*/

#include <iostream>
#include <vector>
#include <string>
#include <algorithm>
using namespace std;

string printSubSequence(string &s1, string &s2,int m, int n ){
    
  vector<vector<int>> dp(m+1,vector<int>(n+1,0));
	  
  for(int i=1;i<=s1.size();i++){
      for(int j=1;j<=s2.size();j++){
          if(s1[i-1]==s2[j-1])
             dp[i][j]=1+dp[i-1][j-1];
          else{
             dp[i][j]=max(dp[i-1][j],dp[i][j-1]);
          }
      }
  }
  int index=dp[m][n];
  char ch[index+1];
  string str(index,'z');
  while(m>0 && n>0){
      if(s1[m-1]==s2[n-1]){
          str[index-1]=s1[m-1];
          index--;
          m--;
          n--;
      }
      else if(dp[m-1][n]>dp[m][n-1])
          m--;
      else
          n--;
  }
  return str;
}

int main(){
   string s1="ABCDGH";
   string s2="AEDFHR";
   
   int m=s1.size();
   int n=s2.size();
   
   
   cout<<printSubSequence(s1,s2,m,n);
   return 0;
}
