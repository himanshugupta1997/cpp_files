#include<iostream>
using namespace std;

class Node{
public:
    int data;
    Node*next;
    Node(int d):data(d),next(NULL){
    }
};

void addAtFront(int d,Node*&head){     /// we use *&head here because here value of head is changing ................
    if(head==NULL){
        head = new Node(d);
    }
    else{
        Node *n = new Node(d);
        n->next = head;
        head = n;
    }
}
void takeInput(Node *&head){    ///taking input till we enter -1 ................

    int d;
    cin>>d;
    while(d!=-1){
        addAtFront(d,head);
        cin>>d;
    }

}
///In this function we are moving head to tail;
void reverse1(Node *&head){
    if(head==NULL||head->next==NULL){
        return;
    }
    Node *prev = NULL;
    Node *current = head;
    Node *next;

    while(current!=NULL){
        next = current->next;
        current->next = prev;

        prev = current;
        current = next;
    }
    head = prev;
}

Node*getMid(Node*head){    ///here we use *head because  here value of head is not changing...............
    if(head==NULL||head->next==NULL){
        return head;
    }
    Node*fast = head->next;
    Node* slow = head;
    while(fast && fast->next){
        fast = fast->next->next;
        slow = slow->next;
    }
    return slow;
}

Node* merge(Node *a,Node *b){
    if(a==NULL){
        return b;
    }
    if(b==NULL){
        return a;
    }
    Node* newHead;
    if(a->data < b->data){
        newHead = a;
        newHead->next = merge(a ->next,b);
    }
    else{
        newHead = b;
        newHead->next = merge(a,b->next);
    }
}
///merge sort.........................
Node* mergeSort(Node*head){
    if(head==NULL||head->next==NULL){
        return head;
    }
    ///Recursive Case
    ///1. Divide into 2 parts
    Node* mid = getMid(head);
    Node* a = head;
    Node* b = mid->next;
    mid->next = NULL;   ///for breaking linked list into 2.............................
    ///2. Recursively Sort the two parts
    a = mergeSort(a);
    b = mergeSort(b);
    ///3. Merge the two aparts
    head = merge(a,b);
    return head;
}
int getLength(Node *head){
    int l=0;
    while(head){
        l++;
        head = head->next;
    }
    return l;
}
///bubble sort...............................
void bubbleSort(Node *&head){
    int n = getLength(head);
    for(int i=0;i<=n-2;i++){
        Node*prev = NULL;
        Node*current  = head;
        Node*N;

        while(current!=NULL && current->next!=NULL){
            if(current->data > current->next->data){
                    if(prev==NULL){
                        N = current->next;
                        current->next = N->next;
                        N->next = current->next;
                        head = N;
                        prev = N;

                    }
                    else{
                            N = current->next;
                            current->next = N->next;
                            N->next = current;
                            prev->next = N;
                            prev = N;
                    }


            }
            else{
                prev = current;
                current = current->next;

            }
        }
    }
}


void print(Node *head){
    while(head!=NULL){
        cout<<head->data<<"--> ";
        head = head->next;
    }
    cout<<endl;
}


int main(){
    Node*head=NULL;
    takeInput(head);
    print(head);
    reverse1(head);
    print(head);
   ///head = mergeSort(head);
    bubbleSort(head);
    print(head);
}
