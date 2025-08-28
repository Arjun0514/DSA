// Online C++ compiler to run C++ program online
#include <iostream>
#include <vector>
using namespace std;

class Node{
   public:
   int data;
   Node* next;
   Node* back;
   
   Node(int data1){
       data=data1,
       next=nullptr;
       back=nullptr;
   }
   Node(int data1, Node* next1, Node* back1){
       data=data1,
       next=next1;
       back=back1;
   }
};

Node* convertArrayToDLL(vector<int> &vec){
    if(vec.empty()){
        return nullptr;
    }
    Node* head= new Node(vec[0]);
    Node* mover=head;
    for(int i=1;i<vec.size();i++){
        Node* newNode= new Node(vec[i]);
        mover->next=newNode;
        newNode->back=mover;
        mover=mover->next;
    }
    return head;
}

void displayDLL(Node* head){
    while(head!=nullptr){
        cout<<head->data<<" ";
        head=head->next;
    }
    cout<<endl;
}

Node* deleteHead(Node* head){
    if(head==nullptr || head->next==nullptr){
        return nullptr;
    }
    Node* mover=head;
    head=head->next;
    head->back==nullptr;
    mover->next=nullptr;
    delete mover;
    mover=nullptr;
    return head;
}

Node* deleteTail(Node* head){
    if(head==nullptr || head->next==nullptr){
        return nullptr;
    }
    Node* mover=head;
    while(mover->next!=nullptr){
        mover=mover->next;
    }
    mover->back->next=nullptr;
    mover->back=nullptr;
    delete mover;
    mover=nullptr;
    return head;
}

Node* deleteKth(Node* head, int k){
    if(k<=0 || head==nullptr){
        cout<<"invalid position"<<endl;
        return head;
    }
    //if position is 1
    if(k==1){
        return deleteHead(head);
    }
    //logic- loop till kth, If between looping ll becomes null then k is invalid position
    Node* mover=head;
    for(int i=1;i<k;i++){
        mover=mover->next;
        if(mover==nullptr){
            cout<<"K is invalid position"<<endl;
            return head;
        }
    }
    mover->back->next=mover->next;
    //If its last node, then it won't have next
    if(mover->next!=nullptr){
        mover->next->back=mover->back;
    }
    mover->next=nullptr;
    mover->back=nullptr;
    delete mover;
    mover=nullptr;
    return head;
}

//here used while loop, time complexity for delete end is 2n
Node* deleteKthOtherAppro(Node* head,int k)
{
    if(head==nullptr){
        return nullptr;
    }
    Node* mover = head;
    int cnt=1;
    while(mover!=nullptr){
        if(cnt==k)
        {
            break;
        }
        cnt++;
        mover=mover->next;
    }
    if(mover==nullptr){
        cout<<"invalid position"<<endl;
        return head;
    }
    Node* prev=mover->back;
    Node* front=mover->next;
    if(prev==nullptr && front==nullptr){
        return nullptr;
    }
    if(prev==nullptr){
        return deleteHead(head);
    }
    if(front==nullptr){
        return deleteTail(head);
    }
    prev->next=front;
    front->back=prev;
    
    mover->next=nullptr;
    mover->back=nullptr;
    delete mover;
    mover=nullptr;
    return head;
}
int main() {
    vector<int> vec= {11,22,33,44,55};
    Node* head= convertArrayToDLL(vec);
    displayDLL(head);
    
    // head= deleteHead(head);
    // displayDLL(head);

    // head= deleteTail(head);
    // displayDLL(head);
    
    // head=deleteKth(head,1);
    // displayDLL(head);

    head=deleteKthOtherAppro(head,3);
    displayDLL(head);
    return 0;
}
