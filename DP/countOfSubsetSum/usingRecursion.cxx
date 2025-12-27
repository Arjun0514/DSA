#include <iostream>
#include <vector>
using namespace std;

int countSum(vector<int> &vec, int target,int n,int currentSum){
    if(n==0){
       return (target==currentSum);
    }
    int pick=0;
    if(currentSum+vec[n-1]<=target){
       pick=countSum(vec,target,n-1,currentSum+vec[n-1]);
    }
    int notPick=countSum(vec,target,n-1,currentSum);
    return (pick+notPick);
}

int main(){
vector<int> vec={3,7,4,6,3};
int target=10;
int sum=0;
cout<<countSum(vec,target,vec.size(),sum);

return 0;
}
