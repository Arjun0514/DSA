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
  if(m==0 || n==0)
	  return "";
  if(s1[m-1]==s2[n-1]){
	 return printSubSequence(s1,s2,m-1,n-1)+s1[m-1];
  }
  else{
      string res1=printSubSequence(s1,s2,m,n-1);
	  string res2=printSubSequence(s1,s2,m-1,n);
	  return res1.size()>res2.size() ? res1:res2;
  }
}

int main(){
   string s1="ABCDGH";
   string s2="AEDFHR";
   
   int m=s1.size();
   int n=s2.size();
   
   cout<<printSubSequence(s1,s2,m,n);
   return 0;
}
