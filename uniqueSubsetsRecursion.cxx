// Online C++ compiler to run C++ program online
#include <iostream>
#include <string>
#include <unordered_set>
using namespace std;

void solve(string ip, string op, unordered_set<string> &u_set){
    if(ip.length()==0){
        u_set.insert(op);
        return;
    }
    
    string op1=op;
    string op2=op;
    
    op2.push_back(ip[0]);
    ip.erase(0,1);
    
    solve(ip,op1,u_set);
    solve(ip,op2,u_set);
}

int main() {
    string ip,op="";
    unordered_set<string> u_set;
    cout<<"enter ip string here"<<endl;
    cin>>ip;
    
    solve(ip, op, u_set);
    for(const auto &s: u_set){
        cout<<s<<" ";
    }
    return 0;
}
