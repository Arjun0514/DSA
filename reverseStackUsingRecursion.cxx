// Online C++ compiler to run C++ program online
#include <iostream>
#include <stack>
using namespace std;
void adjustLast(stack<int> &s, int ele){
    if(s.size()==0){
        s.push(ele);
        return;
    }
    int val= s.top();
    s.pop();
    adjustLast(s,ele);
    s.push(val);
}
void reverseStack(stack<int> &s){
    if(s.size()==1){
        return;
    }
    int temp=s.top();
    s.pop();
    reverseStack(s);
    adjustLast(s,temp);
}

int main() {
    // Write C++ code here
    stack<int> s;
    s.push(11);
    s.push(22);
    s.push(33);
    s.push(44);
    s.push(55);
    
    reverseStack(s);
    
    while (!s.empty()) {
    cout << s.top() << " ";  // print top element
    s.pop();                 // remove it
    }
    return 0;
}
