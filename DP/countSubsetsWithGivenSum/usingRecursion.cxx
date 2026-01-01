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
	
	
	if(n==0){
	    if(target==0)
	      return 1;
	    return 0;
	}
	int pick=0;
	if(vec[n-1]<=target)
	   pick=subSetsWithGivenSums(vec, n-1, target-vec[n-1]);
	   
	int notPick=subSetsWithGivenSums(vec,n-1,target);
	return (pick+notPick);
}
int main(){
 vector<int> vec={0,0,0};
 int diff=0;
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
