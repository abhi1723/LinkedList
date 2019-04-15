#include <iostream>

using namespace std;
class node{
public:
    int data;
    node *next;
    node(int d){
        data=d;
        next=NULL;
    }
};
void insertAtLast(node* &head,int data){
    node* n=new node(data);
    if(head==NULL) head=n;
    else{
            node *temp=head;
            while(temp->next!=NULL)
                temp=temp->next;
            temp->next=n;
    }
}
void printLinkedList(node *head){
    while(head!=NULL){
        cout<<head->data<<" ";
        head=head->next;
    }
}
node * findKthNode(node* head,int k){
    node*fast=head;
    node*slow=head;
    int check=1;
    while(check<=k){
        fast=fast->next;
        check++;
    }
    while(fast!=NULL){
        fast=fast->next;
        slow=slow->next;
    }
    return slow;
}
void lastKAppend(node* &head,int k){
    node* start=head;
    int kMinusOne=k+1;
    node *kMinusOneThNode=findKthNode(head,kMinusOne);
    //cout<<"kMinusOneNode"<<kMinusOneThNode->data<<endl;
    node *kThNode=kMinusOneThNode->next;
    //cout<<"kNode"<<kThNode->data<<endl;
    kMinusOneThNode->next=NULL;
    node *temp=kThNode;
    while(temp->next!=NULL){
        temp=temp->next;
    }
    node *ends=temp;
    ends->next=start;
    //cout<<"endNode"<<ends->data<<endl;
    head=kThNode;
    //cout<<"head node"<<head->data<<endl;
}
void reverseLinkedList(node *&head){
    node * current=head;
    node *next=NULL,*prev=NULL;
    while(current!=NULL){
        next=current->next;
        current->next=prev;
        prev=current;
        current=next;
    }
    head=prev;
}
int main()
{
    node* head=NULL;
    int N,k;
    cin>>N;
    for(int i=0;i<N;i++)
    {
        int input;
        cin>>input;
        insertAtLast(head,input);
    }
    cin>>k;
    if(k>0 && N>1 && k!=N)
    lastKAppend(head,k%N);
    if(k==N)
        reverseLinkedList(head);
    printLinkedList(head);
    return 0;
}
