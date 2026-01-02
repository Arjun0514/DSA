#include <iostream>
#include <vector>
using namespace std;


int countSum(vector<int> &vec,int n,int target){
    if(target==0)
      return 1;
    if(n==0)
       return 0;
    int pick=0;
    if(vec[n-1]<=target){
       pick=countSum(vec,n-1,target-vec[n-1]);
    }
    int notPick=countSum(vec,n-1,target);
    return (pick+notPick);
}

int main(){
vector<int> vec={3,7,6,4,3};
int target=10;
vector<vector<int>> memo(vec.size()+1,vector<int>(target+1,-1));
cout<<countSum(vec,vec.size(),target);

return 0;
}
