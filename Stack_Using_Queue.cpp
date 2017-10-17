#include<iostream>
using namespace std;
struct queue{
	int a[30], f, r;
}q1, q2;
void insert(struct queue* q1, struct queue* q2, int x){
	if(q1->f==-1 && q1->r==-1 && q2->f==-1 && q2->r==-1){
		q1->f = 0;
		q1->r = 0;
		q1->a[q1->r] = x;
	}
	else if((q1->f==-1 && q1->r==-1) && !(q2->f==-1 && q2->r==-1)){
		q2->r++;
		q2->a[q2->r] = x;
	}
	else if((q2->f==-1 && q2->r==-1) && !(q1->f==-1 && q1->r==-1)){
		q1->r++;
		q1->a[q1->r] = x;
	}
}
void del(struct queue* q1, struct queue* q2){
	if(q1->f==-1 && q1->r==-1 && q2->f==-1 && q2->r==-1){
		return;
	}
	else if(q1->f==0 && q1->r==0){
		q1->f = -1;
		q1->r = -1;
	}
	else if(q2->f==0 && q2->r==0){
		q2->f = -1;
		q2->r = -1;
	}
	else if(q1->r>0){
		q2->f = 0;
		while(q1->f!=q1->r){
			q2->r++;
			q2->a[q2->r] = q1->a[q1->f];
			q1->f++;
		}
		q1->f = -1;
		q1->r = -1;
	}
	else{
		q1->f = 0;
		while(q2->f!=q2->r){
			q1->r++;
			q1->a[q1->r] = q2->a[q2->f];
			q2->f++;
		}
		q2->f = -1;
		q2->r = -1;
	}
}
void display(struct queue q1, struct queue q2){
	if(q1.f==-1 && q1.r==-1 && q2.f==-1 && q2.r==-1){
		cout<<"\nEmpty";
	}
	else if(q1.f==0 && q1.r==0){
		cout<<endl<<q1.a[q1.f]<<endl;
	}
	else if(q2.f==0 && q2.r==0){
		cout<<endl<<q2.a[q2.f]<<endl;
	}
	else if(q1.r>0){
		cout<<endl;
		while(q1.r>=q1.f){
			cout<<q1.a[q1.r];
			q1.r--;
			cout<<endl;
		}
	}
	else if(q2.r>0){
		cout<<endl;
		while(q2.r>=q2.f){
			cout<<q2.a[q2.r];
			q2.r--;
			cout<<endl;
		}
	}
}
int main(){
	q1.f = -1;
	q1.r = -1;
	q2.f = -1;
	q2.r = -1;
	while(1){
		cout<<"\n1. Insert\n2. Delete\n3. Exit ";
		int x;
		cin>>x;
		switch(x){
			case 1:
				cout<<"\nEnter the element to be inserted ";
				int f;
				cin>>f;
				insert(&q1, &q2, f);
				display(q1, q2);
				break;
			case 2:
				{
					del(&q1, &q2);
					cout<<"\nDeleted successfully";
					display(q1, q2);
				}
				break;
			case 3:
				exit(0);
			default:
				cout<<"\nEnter correct choice";
		}
	}
}
