#include<bits/stdc++.h>
using namespace std;

class node{

	//we need to make it public otherwise we can't access them.
	public:
    int val;
    node* next;
    //it is a constructor function
    node(int n){
        val=n;
        next=NULL;
    }
};

/**
we will create a function to add element at the end of list
we will be given head. The starting point of linked list.
head is the value by referrence of a node type pointer.It adds another layer of indirection here.
The last element's next= NULL
*/
void insertAtTheTail (node* &head, int val){
	//creating a new node and pointer 'n' will point that.
	//next will be null and value will be val
	node* n=new node(val);
	//there is no node in the list then we need to check otherwise it will point to garbage something
	if(head==NULL){
		head=n;
		return;
	}
	node* temp = head;
	//will go to the last node
	while(temp->next!=NULL){
		temp = temp->next;
	}
	//setting last node->next to new node
	temp->next = n;
}

//inserting at the beginning
void insertingAtTheBeginning(node* &head,int val){
	node* n=new node(val);
	n->next=head;
	head=n;
}
//searching in the list
bool searching(node* &head,int key){
	node* temp=head;
	while(temp!=NULL){
		if(temp->val==key){
			return true;
		}
		temp=temp->next;
	}
	return false;
}

//printing our list
void display(node* &head){
	node* temp=head;
	while(temp!=NULL){
		cout<<temp->val<<" ";
		temp=temp->next;
	}
	cout<<endl;
}
int main(){
	node* head=NULL;
	/**
	even though we save head is NULL.
	After inserting first element it changes to the location of first element,
	even after adding other elements at the end.
	Because we send the reference not the value in the function
	and when it had elements it doesn't change the head anymore.
	You don't believe me?
	ok dipshit...uncomment the printline.
	*/
	//cout<<"No element: "<<head<<endl;
	insertAtTheTail(head,1);
	//cout<<"AFTER inserting first element: "<<head<<endl;
	insertAtTheTail(head,2);
	//cout<<"AFTER inserting second element: "<<head<<endl;
	insertAtTheTail(head,3);
	//cout<<"AFTER inserting third element: "<<head<<endl;
	display(head);
	insertingAtTheBeginning(head,4);
	display(head);
	cout<<searching(head,3)<<endl;
	cout<<searching(head,6)<<endl;
return 0;
}
