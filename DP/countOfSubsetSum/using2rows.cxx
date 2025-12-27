#include <iostream>
#include <vector>
using namespace std;

int countSum(vector<int> &vec, int target,int n){
    
    vector<int> curr(target+1,0),prev(target+1,0);
    curr[0]=prev[0]=1;
    
    for(int i=1;i<=vec.size();i++){
        for(int j=1;j<=target;j++){
            int currentEle=vec[i-1];
            int pick=0;
            if(currentEle<=j){
                pick=prev[j-currentEle];
            }
            int notPick= prev[j];
            curr[j]=pick+notPick;
        }
        prev=curr;
    }
    return prev[target];
}

int main(){
vector<int> vec={3,7,4,6,3};
int target=10;
cout<<countSum(vec,target,vec.size());
return 0;
}
