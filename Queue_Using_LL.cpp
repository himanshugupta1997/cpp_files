#include<iostream>
using namespace std;
struct node{
	int data;
	struct node* next; 
};
struct node* new_node(int x){
	struct node* p = new node;
	p->data = x;
	p->next = NULL;
	return p;
}
void insert(struct node** head, struct node** end, int x){
	struct node* p = new_node(x);
	if(*head==NULL && *end==NULL){
		*head = p;
		*end = p;
		return;
	}
	(*end)->next = p;
	(*end) = p;
}
void del(struct node** head, struct node** end){
	if(*head==NULL && *end==NULL){
		return;
	}
	if((*head)->next==NULL){
		*head = NULL;
		*end = NULL;
		return;		
	}
	struct node* temp = (*head);
	(*head) = (*head)->next;
	delete temp;	
}
void display(struct node* head, struct node* end){
	if(head==NULL && end==NULL){
		cout<<"\nEmpty queue";
		return;
	}
	cout<<"\n";
	while(head!=NULL){
		cout<<head->data<<" ";
		head = head->next;
	}
}
int main(){
	struct node* head = NULL, * end = NULL;
	while(1){
		cout<<"\n1. Insert \n2. Delete \n3. Exit ";
		int x;
		cin>>x;
		switch(x){
			case 1:
				cout<<"\nEnter the element to be inserted ";
				int f;
				cin>>f;
				insert(&head, &end, f);
				display(head, end);
				break;
			case 2:
				del(&head, &end);
				cout<<"\nDeleted successfully";
				display(head, end);
				break;
			case 3:
				exit(0);
			default:
				cout<<"\nEnter the right choice\n";		
		}
	}
}
