// Online C++ compiler to run C++ program online
#include <iostream>
using namespace std;

//Print n to 1
void printNto1(int num){
   if(num==0){
       return;
   } 
   cout<<num<<" ";
   printNto1(num - 1); 
}

//Print 1 to n
void print1toN(int num){
   if(num==0){
       return;
   } 
   print1toN(num - 1);
   cout<<num<<" ";
   
}

int fact(int num){
    if(num==1 || num ==0){
        return 1;
    }
    return fact(num-1)*num;
}
int main() {
    int num;
    cout<<"enter a number";
    cin>>num;
    
    printNto1(num);
    cout<<endl;
    print1toN(num);
    cout<<endl;
    int n=fact(num);
    cout<<"factorial of "<<num<<" is "<<n;
    
    return 0;
}
