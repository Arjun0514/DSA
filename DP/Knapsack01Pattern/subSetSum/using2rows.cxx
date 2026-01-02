#include <iostream>
#include <vector>
using namespace std;

bool subSetSum(vector<int> &set, int target, int n){

     vector<bool> prev(target+1,false),curr(target+1);
     prev[0]=curr[0]=true;
     
     for (int i=1;i<=n;i++){
         for(int j=1;j<=target;j++){
             int currentWeight=set[i-1];
             int pick=false;
             if(currentWeight<=j){
                 pick=prev[j-currentWeight];
             }
             int notPick=prev[j];
             curr[j]=pick||notPick;
         }
         prev=curr;
     }
     return prev[target];
}

int main(){
vector<int> set= {3,7,4,9,5};
int target=16;
if (subSetSum(set, target,set.size()))
        cout << "True" << endl;
    else
        cout << "False" << endl;

return 0;
}
