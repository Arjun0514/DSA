//count the number of subsets with given difference
#include <iostream>
#include <vector>
#include <algorithm>
using namespace std;

int subSetsWithGivenSums(vector<int> &vec, int n, int target){
	/* 1) use include, exlude approach 
	   2) in end add all subsets find from include and exlude approach
	   3) base case- when target becomes 0 return 1(it means we found subset with given sum)
	   4) when n becomes 0 return 0(it means we don't found any subset with given sum)*/
	vector<vector<int>> dp(vec.size()+1,vector<int>(target+1,0));
	
	for(int i=0;i<=vec.size();i++){
	    dp[i][0]=1;
	}
	for(int i=1;i<=n;i++){
	    for(int j=1;j<=target;j++){
	        int current=vec[i-1];
	        int pick=0;
	        if(current<=j)
	           pick=dp[i-1][j-current];
	        int notPick=dp[i-1][j];
	        dp[i][j]=pick+notPick;
	    }
	}
	return dp[n][target];
}
int main(){
 vector<int> vec={1,1,2,3,8};
 int diff=1;
 //s1-s2=1
 //s1+s2=totalsum
 //adding up above 2 solutions will give 2s1=1+totalsum;
 //So we have to calculate how many s1= 4;
 // we have solved this already... count the number of subsets with given sum
 int totalsum=0;
 for(int i=0;i<vec.size();i++){
    totalsum=totalsum+vec[i];
 }
 
 if((diff+totalsum)%2!=0){
    cout<<"there are 0 subsets with given difference";
    return 0;
 }
 
 int target= (diff+totalsum)/2;
 
 
 cout<<subSetsWithGivenSums(vec,vec.size(),target);
 return 0;
}
