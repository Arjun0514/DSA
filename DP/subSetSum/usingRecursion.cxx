#include <iostream>
#include <vector>
using namespace std;

bool subSetSum(vector<int> &set, int target, int n){
     if (target==0){
         return true;
     }
     if (n==0){
         return false;
     }
     bool pick=false;
     if(target>=set[n-1]){
         pick=subSetSum(set, target-set[n-1], n-1);
     }
     bool notPick=subSetSum(set, target, n-1);
     return (pick || notPick);
     
}

int main(){
vector<int> set= {3,7,4,9,5};
int target=10;
if (subSetSum(set, target,set.size()))
        cout << "True" << endl;
    else
        cout << "False" << endl;

return 0;
}
