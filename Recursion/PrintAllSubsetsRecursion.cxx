// Online C++ compiler to run C++ program online
#include <iostream>
#include <string>
using namespace std;

void solve(string ip,string op){
    if(ip.length()==0){
        cout<<op<<" "<<endl;
        return;
    }
    
    string op1=op;
    string op2=op;
    op2.push_back(ip[0]);
    
    ip.erase(0,1);
    
    solve(ip,op1);
    solve(ip,op2);
    
}
int main() {
    // Write C++ code here
    string ip;
    cout<<"enter string"<<endl;
    cin>>ip;
    
    string op;
    solve(ip,op);
    return 0;
}
