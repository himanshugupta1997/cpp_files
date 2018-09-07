#include<iostream>
#include<queue>
#include<cmath>
using namespace std;
class TreeNode{
    public:
    int data;
    TreeNode*left;
    TreeNode*right;

    TreeNode(int d):data(d),left(NULL),right(NULL){
    }
};

TreeNode* levelOrderInput(){
    int d;
    cout<<"Enter root data";
    cin>>d;
    TreeNode* root = new TreeNode(d);

    queue<TreeNode*> q;
    q.push(root);

    while(!q.empty()){
        TreeNode* f = q.front();
        q.pop();

        cout<<"Enter children of "<<f->data<<" ";
        int d1,d2;
        cin>>d1>>d2;
        if(d1!=-1){
            TreeNode* leftchild = new TreeNode(d1);
            f->left = leftchild;
            q.push(leftchild);
        }
        if(d2!=-1){
            TreeNode*rightChild = new TreeNode(d2);
            f->right = rightChild;
            q.push(rightChild);
        }
    }
    return root;
}
void levelOrderPrint(TreeNode*root){

    queue<TreeNode*> q;
    q.push(root);
    q.push(NULL);

    while(!q.empty()){
        TreeNode* f = q.front();
        if(f==NULL){
            cout<<endl;
            q.pop();
            if(!q.empty()){
                q.push(NULL);
            }
        }
        else{
            cout<< f->data <<" ";
            q.pop();
            if(f->left!=NULL){
                q.push(f->left);
            }
            if(f->right!=NULL){
                q.push(f->right);
            }
        }
    }
}
int height(TreeNode*root){
    if(root==NULL){
        return 0;
    }
    return 1 + max(height(root->left),height(root->right));
}
int diameter(TreeNode*root){
    if(root==NULL){
        return 0;
    }
    int op1 = diameter(root->left);
    int op2 = diameter(root->right);
    int op3 = height(root->left) + height(root->right);
    return max( op1, max(op2,op3));

}
class Pair{
public:
    int height;
    int diameter;
};

Pair fastDiameter(TreeNode*root){
    Pair p;
    ///Base Case
    if(root==NULL){
        p.diameter = 0;
        p.height = 0;
        return p;
    }
    Pair left = fastDiameter(root->left);
    Pair right = fastDiameter(root->right);

    int op1 = left.diameter;
    int op2 = right.diameter;
    int op3 = left.height + right.height;

    p.diameter = max(op1,max(op2,op3));
    p.height = max(left.height,right.height)+1;
    return p;

}

TreeNode* search(TreeNode*root,int key){
    if(root==NULL){
        return NULL;
    }
    if(root->data==key){
        return root;
    }
    TreeNode*leftAns = search(root->left,key);
    if(leftAns!=NULL){
        return leftAns;
    }
    else{
        return search(root->right,key);
    }
}
void mirror(TreeNode*root){
    if(root==NULL){
        return;
    }
    swap(root->left,root->right);
    mirror(root->left);
    mirror(root->right);
}




int countNodes(TreeNode*root){
    if(root==NULL){
        return 0;
    }
    return 1+ countNodes(root->left)
    +countNodes(root->right);
}

TreeNode* insertBST(TreeNode*root,int key){
    if(root==NULL){
        TreeNode* root = new TreeNode(key);
        return root;
    }
    ///Otherwise ?
    if(key <= root->data){
        root->left = insertBST(root->left,key);
    }
    else{
        root->right = insertBST(root->right,key);
    }
    return root;
}
TreeNode* takeBST(){
    int no;
    cin>>no;
    TreeNode* root= NULL;
    while(no!=-1){
        root = insertBST(root,no);
        cin>>no;
    }
    return root;
}

class LinkedList{
public:
    TreeNode*head;
    TreeNode* tail;
};

LinkedList convertBSTtoLL(TreeNode*root){
    LinkedList l;

    if(root->left==NULL && root->right==NULL){
        l.head = root;
        l.tail = root;
        return l;
    }
    else if(root->left==NULL && root->right!=NULL){
        LinkedList rightLL = convertBSTtoLL(root->right);
        l.head = root;
        root->right = rightLL.head;
        l.tail = rightLL.tail;
        return l;

    }
    else if(root->left!=NULL && root->right==NULL){
        LinkedList leftLL = convertBSTtoLL(root->left);
        leftLL.tail->right = root;

        l.tail = root;
        l.head = leftLL.head;
        return l;

    }
    else{
        LinkedList leftLL = convertBSTtoLL(root->left);
        LinkedList rightLL = convertBSTtoLL(root->right);
        leftLL.tail->right = root;
        root->right = rightLL.head;

        l.head = leftLL.head;
        l.tail = rightLL.tail;
        return l;


    }




}



TreeNode* searchBST(TreeNode*root,int key){
    if(root==NULL){
        return NULL;
    }
    if(root->data==key){
        return root;
    }
    if(root->data > key){
        return searchBST(root->left,key);
    }
    else{
        return searchBST(root->right,key);
    }
}

void printPreorder(TreeNode *root){
    if(root==NULL){
        return;
    }
    cout<<root->data<<" ";
    printPreorder(root->left);
    printPreorder(root->right);

}

void printInorder(TreeNode *root){
    if(root==NULL){
        return;
    }
    printInorder(root->left);
    cout<<root->data<<" ";
    printInorder(root->right);

}

void printPostOrder(TreeNode *root){
    if(root==NULL){
        return;
    }
    printPostOrder(root->left);
    printPostOrder(root->right);
    cout<<root->data<<" ";

}
class sumPair{
public:
    int inc;
    int exc;
};
sumPair maxSumUsingParentOrChild(TreeNode*root){
    sumPair p;
    if(root==NULL){
        p.inc = 0;
        p.exc  = 0;
        return p;
    }
    sumPair leftSum = maxSumUsingParentOrChild(root->left);
    sumPair rightSum = maxSumUsingParentOrChild(root->right);


    p.inc  = root->data + leftSum.exc + rightSum.exc;
    p.exc = max(leftSum.inc,leftSum.exc) + max(rightSum.inc,rightSum.exc);
    return p;

}

TreeNode* arrayToBST(int a[],int s,int e){
    if(s>e){
        return NULL;
    }

    int mid = (s+e)/2;
    TreeNode* n = new TreeNode(a[mid]);
    n->left = arrayToBST(a,s,mid-1);
    n->right = arrayToBST(a,mid+1,e);
    return n;
}
bool isBST(TreeNode* root,int min_v = INT_MIN,int max_v = INT_MAX){
    if(root==NULL){
        return true;
    }
    bool isLeftBST = isBST(root->left,min_v,root->data);
    bool isRightBST = isBST(root->right,root->data,max_v);

    if( isLeftBST && isRightBST &&
        root->data > min_v && root->data < max_v){
        return true;
    }
    else{
        return false;
    }


}

pair<int,bool> isBalanced(TreeNode*root){
        pair<int,bool> p;
    if(root==NULL){
            p.first = 0;
            p.second = true;
            return p;
    }
    pair<int,bool> left,right;
    left = isBalanced(root->left);
    right = isBalanced(root->right);

    if(left.second==true && right.second==true&&
       abs(left.first-right.first)<=1){
       p.first = max(left.first,right.first)+1;
       p.second = true;
       return p;

    }
    else{
       p.first = max(left.first,right.first)+1;
       p.second = false;
       return p;
    }


}

int main(){
    int a[] = {1,3,15,7,8,10,12};
    TreeNode* root = arrayToBST(a,0,6);
    //TreeNode* root = levelOrderInput();
    levelOrderPrint(root);
    sumPair p = maxSumUsingParentOrChild(root);

    cout<<"Max sum inc root is "<<p.inc<<endl;

    cout<<"Max sum exc root is "<<p.exc<<endl;

    if(isBST(root)){
        cout<<"Yes it is a bst "<<endl;
    }
    else{
        cout<<"Not a bst "<<endl;
    }
    if(isBalanced(root).second){
            cout<<"Balanced hai !"<<endl;

    }



    return 0;
}
