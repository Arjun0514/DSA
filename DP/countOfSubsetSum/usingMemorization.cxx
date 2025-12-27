#include <iostream>
#include <vector>
using namespace std;


int countSum(vector<int> &vec, int target,int n,int currentSum,vector<vector<int>>&memo){
    if(n==0){
       return (target==currentSum);
    }
    
    if(memo[n][currentSum]!=-1){
        return memo[n][currentSum];
    }
    int pick=0;
    if(currentSum+vec[n-1]<=target){
       pick=countSum(vec,target,n-1,currentSum+vec[n-1],memo);
    }
    int notPick=countSum(vec,target,n-1,currentSum,memo);
    return memo[n][currentSum]=(pick+notPick);
      

}

int main(){
vector<int> vec={3,7,4,6,3};
int target=10;
int sum=0;
vector<vector<int>> memo(vec.size()+1,vector<int>(target+1,-1));
memo[0][0]=1;
cout<<countSum(vec,target,vec.size(),sum,memo);

return 0;
}
