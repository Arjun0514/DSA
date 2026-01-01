#include <iostream>
#include <vector>
using namespace std;

int minDiff(vector<int> &vec,int n,int subset1,int totalSum,vector<vector<int>> &memo){
    if(n==0)
		return abs(subset1-(totalSum-subset1));
		
	if(memo[n][subset1]!=-1)
	    return memo[n][subset1];
	
	int pick= minDiff(vec,n-1,subset1+vec[n-1],totalSum,memo);
	int notPick=minDiff(vec,n-1,subset1,totalSum,memo);
	
	return memo[n][subset1]=min(pick,notPick);
}

int main(){
	
vector<int> vec= {1,6,11,5,3};
  int totalSum=0;
  for(int i=0;i<vec.size();i++){
      totalSum=totalSum+vec[i];
  }
  int subset1=0;
  
  vector<vector<int>> memo(vec.size()+1,vector<int>(totalSum+1,-1));
  cout<<minDiff(vec,vec.size(),subset1,totalSum,memo);
return 0;
}
