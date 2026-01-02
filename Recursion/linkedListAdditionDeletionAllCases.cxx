/******************************************************************************

                              Online C++ Compiler.
               Code, Compile, Run and Debug C++ program online.
Write your code in this editor and press "Run" button to compile and execute it.

*******************************************************************************/

#include <iostream>
#include <vector>
using namespace std;

class Node{
    public:
    int data;
    Node* next;
    
    Node(int data1){
        data = data1;
        next = nullptr;
    }
    Node(int data1, Node* next1){
        data=data1;
        next=next1;
    }
};

Node* convertArraytoLL(vector<int> &vec){
    if (vec.empty()){
        return nullptr;
    }
    
    Node* head= new Node(vec[0]);
    Node* mover = head;
    for(int i=1; i<vec.size(); i++)
    {
        Node* newNode = new Node(vec[i]);
        mover->next =newNode;
        mover=newNode;
    }
    return head;
}

void displayLL(Node* mover){
    while(mover){
        cout<<mover->data<<" ";
        mover=mover->next;
    }
    cout<<endl;
}

Node* addNodeAtEnd(Node* head,int data){
    Node* newNode= new Node(data);
    Node* mover=head;
    
    if(head==nullptr){
        return newNode;
    }
    
    while(mover->next!=nullptr){
        mover=mover->next;
    }
    mover->next=newNode;
    return head;
}

Node* addNodeAtStart(Node* head,int data){
    return new Node(data, head);
    //or
    // Node* newNode= new Node(data);
    // newNode->next=head;
    // head=newNode;
    // return head;
    
}

Node* addNodeAtSpecificPos(Node* head,int pos,int data){
    Node* newNode= new Node(data);
    Node* mover=head;
    if(head==nullptr || pos==1){
        return addNodeAtStart(head,data);
        
    }
    for(int i=1;i<pos-1;i++){
        if(mover->next==nullptr){
            break;
        }
        mover=mover->next;
    }
    newNode->next=mover->next;
    mover->next=newNode;
    return head;
}

Node* deleteHead(Node* head){
    if(head==nullptr){
        return head;
    }
    Node* temp=head;
    head= head->next;
    free(temp);
    return head;
}
Node* delateTail(Node* head){
    if(head==nullptr){
        return nullptr;
    }
    else if(head->next==nullptr){
        free(head);
        return nullptr;
    }
    Node* mover= head;
    while(mover->next->next!=nullptr){
        mover=mover->next;
    }
    Node* temp= mover->next;
    mover->next=nullptr;
    free(temp);
    return head;
    
}

Node* deleteAtSpec(Node* head,int pos){
    if(pos==1){
        Node* temp=head;
        head=head->next;
        free(temp);
        return head;
        }
          
    Node* mover=head;
    Node* prev=nullptr;
    
    for(int i=1; i<pos; i++){
        prev=mover;
        mover=mover->next;
        if(mover==nullptr){
            cout<<"invalid position"<<endl;
            return head;
        }
    }
    
    prev->next=mover->next;
    free(mover);
    return head;
}

Node* deleteElement(Node* head,int data){
    if(head->data==data){
        Node* temp=head;
        head=head->next;
        free(temp);
        return head;
    }
    
    Node* mover=head;
    Node* prev=nullptr;
    while(mover){
        if(mover->data==data){
            prev->next=mover->next;
            free(mover);
            break;
        }
        prev=mover;
        mover=mover->next;
    }
    return head;
}

Node* insertBeforeElement(Node* head,int element,int elementToAdd){
    Node* newNode=new Node(elementToAdd);
    if(head->data==element){
        return new Node(elementToAdd,head);
    }
    Node* mover=head;
    Node* prev=nullptr;
    while(mover!=nullptr)
    {
        if(mover->data==element){
            newNode->next=mover;
            prev->next=newNode;
            break;
        }
        prev=mover;
        mover=mover->next;
    }
    return head;
}

int main()
{
    vector<int> vec = {11,22,33,44,55,66};
    
    Node* head = convertArraytoLL(vec);
    
    displayLL(head);
    
    // head= addNodeAtEnd(head,66);
    //  displayLL(head);
    
    //  head = addNodeAtStart(head,5);
    //  displayLL(head);
    
    //  head = addNodeAtSpecificPos(head,1,35);
    //  displayLL(head);
    head = insertBeforeElement(head,11,57);
    displayLL(head);
    
    //Deletion
    // head = deleteHead(head);
    // displayLL(head);
    
    // head = delateTail(head);
    // displayLL(head);
    
    // head=deleteAtSpec(head,1);
    // displayLL(head);
    
    // head=deleteElement(head,77);
    // displayLL(head);
    
    free(head);
    return 0;
}
