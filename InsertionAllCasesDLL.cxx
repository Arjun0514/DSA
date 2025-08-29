// Online C++ compiler to run C++ program online
#include <iostream>
#include<vector>
using namespace std;

class Node{
  public:
  int data;
  Node* next;
  Node* back;
  
  Node(int data, Node* next, Node* back){
      this->data=data;
      this->next=next;
      this->back=back;
  }
  Node(int data){
      this->data=data;
      this->next=nullptr;
      this->back=nullptr;
  }
};

Node* convertArrayToDLL(vector<int> &vec){
    if(vec.empty()){
        return nullptr;
    }
    Node* head=new Node(vec[0]);
    Node* mover=head;
    for(int i=1;i<vec.size();i++){
        Node* newNode=new Node(vec[i]);
        mover->next=newNode;
        newNode->back=mover;
        mover=mover->next;
    }
    return head;
}
void displayDLL(Node* mover){
    while(mover!=nullptr){
        cout<<mover->data<<" ";
        mover=mover->next;
    }
    cout<<endl;
}

int sizeOfDLL(Node* mover){
    int cnt=0;
    while(mover!=nullptr){
        cnt++;
        mover=mover->next;
    }
    return cnt;
}

Node* insertBeforeHead(Node* head,int data){
    if(head==nullptr){
        return new Node(data);
    }
    return new Node(data,head,nullptr);
}
Node* insertAtEnd(Node* head,int data){
    if(head==nullptr){
        return new Node(data);
    }
    Node* mover=head;
    while(mover->next!=nullptr){
        mover=mover->next;
    }
    Node* newNode=new Node(data,nullptr,mover);
    mover->next=newNode;
    return head;
    
}

Node* insertBeforeTail(Node* head,int data){
    if(head==nullptr || head->next==nullptr){
        return insertBeforeHead(head,data);
    }
    Node* mover=head;
    while(mover->next!=nullptr){
        mover=mover->next;
    }
    Node* prev=mover->back;
    Node* newNode=new Node(data,mover,prev);
    mover->back=newNode;
    prev->next=newNode;
    return head;
    
}
Node* insertAtKth(Node* head,int data,int k){
    if(head==nullptr || k==1){
        return insertBeforeHead(head,data);
    }
    
    if(k==sizeOfDLL(head)+1){
        return insertAtEnd(head,data);
    }
    
    Node* mover=head;
    for(int i=1;i<k;i++){
        mover=mover->next;
        if(mover==nullptr){
            cout<<"invalid position"<<endl;
            return head;
        }
    }
    Node* newNode= new Node(data,mover,mover->back);
        mover->back->next=newNode;
        mover->back=newNode;
    return head;
}



Node* insertBeforeGivenElement(Node* head, int data, int ele){
    if(head==nullptr){
        return nullptr;
    }
    if(head->data==data ){
        return insertBeforeHead(head,ele);
    }
    Node* mover= head;
    while(mover!=nullptr){
        if (mover->data==data){
        Node* newNode= new Node(ele,mover,mover->back);
        mover->back->next=newNode;
        mover->back=newNode;
        return head;
        }
        mover=mover->next;
    }
    return head;
}
int main() {
    vector<int> vec={11,22,33,44,55};
    Node * head=convertArrayToDLL(vec);
    displayDLL(head);
    
    // head=insertBeforeHead(head,2);
    // displayDLL(head);
    
    // head=insertAtEnd(head,66);
    // displayDLL(head);
    
    // head=insertBeforeTail(head,9);
    // displayDLL(head);
    
    // head=insertAtKth(head,35,7);
    // displayDLL(head);
    
    head=insertBeforeGivenElement(head, 11, 29);
    displayDLL(head);
    return 0;
}
