class Solution {
public:
    int findTheWinner(int n, int k) {
        vector<int> vec;
        for(int i=1;i<=n ;i++){
            vec.push_back(i);
            cout<<i<<" ";
        }
        int index=0;
        int ans=-1;
        k=k-1;
        solve(k,vec,index,ans);
        return ans;
    }
    void solve(int k, vector<int> vec,int index, int &ans){
        if(vec.size()==1){
            ans=vec[0];
            return;
        }
        index = (index+k) % vec.size();
        vec.erase(vec.begin()+index);
        solve(k,vec,index,ans);
    }
};
