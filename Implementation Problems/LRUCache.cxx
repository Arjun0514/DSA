#include <iostream>
#include <unordered_map>

using namespace std;

class LRUCache{
    	  int capacity;
public:
	  
	  class Node{
	     //check access of elements if i declare them outside public
	   public:
	     Node* next;
		 Node* prev;
		 int key;
		 int val;
              Node(int k,int v){
                 key=k;
				 val=v;
			  }				  
	  };
	  
	  unordered_map<int,Node*> mp;
	  Node* head;
	  Node* tail;
      LRUCache(int cap){
			capacity =cap;
			head=new Node(-1,-1);
			tail=new Node(-1,-1);
			head->next =tail;
			tail->prev=head;
	  }
	  
	  void deleteNode(Node* current){
			Node* prevv=current->prev;
			Node* nextt=current->next;
			
			prevv->next=nextt;
			nextt->prev=prevv;	
	  }
	  
	  void addNodeBeforeTail(Node* current){
		   Node* temp=tail->prev;
		   current->next=tail;
		   current->prev=tail->prev;
		   temp->next=current;
		   tail->prev=current;
	  }
	  
	  int get(int key){
           if(mp.count(key)){
               deleteNode(mp[key]);
		       addNodeBeforeTail(mp[key]);
		       return mp[key]->val;
           }  
           else 
              return -1;
	  }
	  
	  void put(int key, int value){
		  
		     if(mp.count(key)){
				mp[key]->val=value;
				deleteNode(mp[key]);
				addNodeBeforeTail(mp[key]);
			 }
			 else{
                if(mp.size()==capacity){
                    Node* temp=head->next;
                    mp.erase(temp->key);
                    deleteNode(temp);
                    delete temp;
                }
				Node* newNode=new Node(key,value);
				addNodeBeforeTail(newNode);
				mp[key]=newNode;
      
			 }
		  
	  }
};

int main(){
	int capacity=4;
	LRUCache lru(capacity);
	
	lru.put(1,11);
	lru.put(2,22);
	lru.put(3,33);
	lru.put(4,44);
	lru.put(7,55);
    cout<<lru.get(2);
    lru.put(9,10);
    cout<<lru.get(3);
	cout<<lru.get(3);
	lru.put(5,66);
	// (4->44)-> (2->55)->(1->11) ->(5->66)
}
