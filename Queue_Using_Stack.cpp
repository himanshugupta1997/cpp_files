#include<iostream>
#include<iomanip>
#include<stdlib.h>
using namespace std;
struct stack{
    int arr[10];
    int top;
};
void enqueue(struct stack *s1, struct stack *s2, int x){
    if(s1->top==-1 && s2->top==-1){
        s1->top++;
        s1->arr[s1->top] = x;
        return;
    }
    if(s1->top>=9){
        cout<<"\nFull";
        return;
    }
    if(s2->top==-1 && s1->top<9){
        s1->top++;
        s1->arr[s1->top] = x;
        return;
    }
    if(s1->top==-1){
        while(s2->top!=-1){
            s1->top++;
            s1->arr[s1->top] = s2->arr[s2->top];
            s2->top--;
        }
        s1->top++;
        s1->arr[s1->top] = x;
        return;
    }
}
void dequeue(struct stack *s1, struct stack *s2){
    if(s1->top==-1 && s2->top==-1){
        return;
    }
    if(s1->top==-1){
        s2->top--;
        return;
    }
    if(s2->top==-1){
        while(s1->top!=-1){
            s2->top++;
            s2->arr[s2->top] = s1->arr[s1->top];
            s1->top--;
        }
        s2->top--;
        return;
    }
}
void display(struct stack s1, struct stack s2){
    if(s1.top==-1 && s2.top==-1){
        cout<<"\nEmpty";
        return;
    }
    if(s2.top==-1){
        int x = 0;
        cout<<"\n";
        while(x!=s1.top+1){
            cout<<s1.arr[x]<<"  ";
            x++;
        }
        return;
    }
    if(s1.top==-1){
        cout<<"\n";
        while(s2.top!=-1){
            cout<<s2.arr[s2.top]<<"  ";
            s2.top--;
        }
        return;
    }
}
int main(){
    struct stack s1, s2;
    s1.top = -1;
    s2.top = -1;
    while(1){
        cout<<"\n\n1. Insert\n2. Delete\n3. Exit ";
        int x;
        cin>>x;
        switch(x){
            case 1:
                cout<<"\nEnter the number to be inserted ";
                int k;
                cin>>k;
                enqueue(&s1, &s2, k);
                display(s1, s2);
                break;
            case 2:
                dequeue(&s1, &s2);
                cout<<"\nDeleted successfully"
                display(s1, s2);
                break;
            case 3:
                exit(0);
            default:
                cout<<"\nEnter a valid choice";
        }
    }
}

