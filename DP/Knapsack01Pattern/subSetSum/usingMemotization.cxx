#include <iostream>
#include <vector>
using namespace std;

bool subSetSum(vector<int> &set, int target, int n, vector<vector<int>> memo){
     if (target==0){
         return true;
     }
     if (n==0){
         return false;
     }
     
     if (memo[n][target]!=-1){
         return memo[n][target];
     }
     bool pick=false;
     if(target>=set[n-1]){
         pick=subSetSum(set, target-set[n-1], n-1,memo);
     }
     bool notPick=subSetSum(set, target, n-1,memo);
     return memo[n][target]=(pick || notPick);
}

int main(){
vector<int> set= {3,7,4,9,5};
int target=6;
vector<vector<int>> memo(set.size()+1,vector<int>(target+1,-1));
if (subSetSum(set, target,set.size(),memo))
        cout << "True" << endl;
    else
        cout << "False" << endl;

return 0;
}
