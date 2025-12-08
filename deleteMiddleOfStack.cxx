// Online C++ compiler to run C++ program online
#include <iostream>
#include <stack>
using namespace std;
void deleteMiddle(stack<int> &s, int k){
    if(k==1){
        s.pop();
        return;
    }
    int temp=s.top();
    s.pop();
    deleteMiddle(s,k-1);
    s.push(temp);
}
int main() {
    // Write C++ code here
    stack<int> s;
    s.push(11);
    s.push(22);
    s.push(33);
    s.push(44);
    s.push(55);
    int k = (s.size()+1)/2;
    
    deleteMiddle(s,k);
    while (!s.empty()) {
    cout << s.top() << " ";  // print top element
    s.pop();                 // remove it
    }
    return 0;
}
