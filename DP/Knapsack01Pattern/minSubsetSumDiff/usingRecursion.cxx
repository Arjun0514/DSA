#include <iostream>
#include <vector>
using namespace std;

int minDiff(vector<int> &vec,int n,int subset1,int totalSum){
    if(n==0)
		return abs(subset1-(totalSum-subset1));
	
	int pick= minDiff(vec,n-1,subset1+vec[n-1],totalSum);
	int notPick=minDiff(vec,n-1,subset1,totalSum);
	
	return min(pick,notPick);
}

int main(){
	
vector<int> vec= {1,6,11,5};
  int totalSum=0;
  for(int i=0;i<vec.size();i++){
      totalSum=totalSum+vec[i];
  }
  int subset1=0;
  cout<<minDiff(vec,vec.size(),subset1,totalSum);
return 0;
}
