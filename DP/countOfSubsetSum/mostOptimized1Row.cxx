#include <iostream>
#include <vector>
using namespace std;

int countSum(vector<int> &vec, int target,int n){
    
    vector<int> dp(target+1,0);
    dp[0]=1;
    for(int i=0;i<vec.size();i++){
        int currentEle=vec[i];
        for(int j=target;j>=currentEle;j--){//for(int j=target;j>=0;j--) is also valid
            int currentEle=vec[i];
            if(currentEle<=j){
                dp[j]=dp[j]+dp[j-currentEle];
            }
        }
    }
    return dp[target];
}

int main(){
vector<int> vec={3,7,4,6,3};
int target=10;
cout<<countSum(vec,target,vec.size());
return 0;
}
