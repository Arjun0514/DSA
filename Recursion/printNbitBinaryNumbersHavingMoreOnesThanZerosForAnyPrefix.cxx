// Online C++ compiler to run C++ program online
#include <iostream>
#include <string>
#include <vector>

using namespace std;

void solve ( int N, int ones, int zeros, string op, vector<string> &vec ){
    if(N==0){
        vec.push_back(op);
        return;
    }
    
    string op1=op;
    op1.push_back('1');
    solve(N-1,ones+1,zeros,op1,vec);
    
    if(zeros<ones){
        string op2=op;
        op2.push_back('0');
        
        solve(N-1,ones,zeros+1,op2,vec);
    }
}
int main() {
    int zeros,ones,N;
    zeros=0;
    ones=0;
    string op;
    vector <string> vec;
    cout << "Enter N"<<endl;
    cin >> N;
    
    solve(N,ones,zeros,op,vec);
    
    for(const auto &v : vec){
        cout<<v<<endl;
    }
    
    return 0;
}
