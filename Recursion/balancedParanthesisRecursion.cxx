// Online C++ compiler to run C++ program online
#include <iostream>
#include <string>
#include <vector>

using namespace std;

void solve(string op, int open, int close,vector<string> &vec){
    if(open==0 && close==0){
        vec.push_back(op);
        return;
    }
    if(open!=0){
        string op1=op;
        op1.push_back('{');
        solve(op1,open-1,close,vec);
    }
    if(close>open){
        string op2=op;
        op2.push_back('}');
        solve(op2,open,close-1,vec);
    }
}
int main() {
    // Write C++ code here
    int num;
    string op="";
    cout << "Enter number of paranthesis"<<endl;
    cin>>num;
    int open=num;
    int close=num;
    vector<string> vec;
    solve(op,open,close,vec);
    for(const auto &v : vec){
        cout<<v<<endl;
    }
    
    return 0;
}
