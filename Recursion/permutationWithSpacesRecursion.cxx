// Permutation with spaces
#include <iostream>
#include <string>
using namespace std;

void solve(string ip,string op){
    if(ip.length()==0){
        cout<<op<<endl;
        return;
    }
    
    string op1=op;
    string op2=op;
    op1.push_back(ip[0]);
    op2.push_back(' ');
    op2.push_back(ip[0]);
    ip.erase(0,1);
    
    solve(ip,op1);
    solve(ip,op2);
    
}
int main() {
    // Write C++ code here
    string ip,op="";
    cout<<"enter string"<<endl;
    cin>>ip;
    op.push_back(ip[0]);
    ip.erase(0,1);
    solve(ip,op);
    return 0;
}
