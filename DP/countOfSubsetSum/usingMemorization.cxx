#include <iostream>
#include <vector>
using namespace std;


int countSum(vector<int> &vec,int n,int target, vector<vector<int>>&memo){
    if(target==0)
      return 1;
    if(n==0)
       return 0;
    if(memo[n][target]!=-1){
        return memo[n][target];
    }
    int pick=0;
    if(vec[n-1]<=target){
       pick=countSum(vec,n-1,target-vec[n-1],memo);
    }
    int notPick=countSum(vec,n-1,target,memo);
    return memo[n][target]=(pick+notPick);
}

int main(){
vector<int> vec={1,1,1};
int target=0;
vector<vector<int>> memo(vec.size()+1,vector<int>(target+1,-1));
cout<<countSum(vec,vec.size(),target,memo);

return 0;
}
