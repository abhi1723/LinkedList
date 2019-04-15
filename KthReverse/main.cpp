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
void insertAtHead(node *&head,int d){
    node *n=new node(d);
    n->next=head;
    head=n;
}
void insertAtLast(node *&head,int data){
    node *n=new node(data);
    node *prev=NULL;
    if(head==NULL) head=n;
    else {
        node *tail=head;
        while(tail->next !=NULL){
            prev=tail;
            tail=tail->next;
        }
        tail->next=n;
    }
}

void printLinkedList(node *head){
    cout<<"Printing "<<endl;
    while(head!=NULL){
        cout<<head->data<<" ";
        head=head->next;
    }
    cout<<endl;
}
node* getThirdHead(node* head){
    int p=1;
    while(p<3){
        if(head->next!=NULL)
            head=head->next;
        p++;
    }
    return head;
}
node* reverseLinkedList(node* head,node *tail){
    //cout<<"The value of head is "<<head->data<<endl;
    node *q=head;
    if(head==tail) {cout<<"head data before return is "<<head->data<<endl;return head;}
    node *n=reverseLinkedList(head->next,tail);
    head->next->next=head;
    head->next=NULL;
    //printLinkedList(tail);
    //cout<<"q data "<<q->data<<endl;
    return n;
}
node* KthReverse(node *head,int k){
    if(head==NULL || head->next==NULL)
        return head;
    int c=0;
    node *prev=NULL,*nextNode=NULL;
    node *current=head;
    while(c<k){
        nextNode=current->next;
        current->next=prev;
        prev=current;
        current=nextNode;
        c++;
    }
    if(nextNode!=NULL)
    head->next=KthReverse(nextNode,k);
    return prev;
}
int main()
{
    node *head=NULL;
    int N,K;
    cin>>N>>K;
    for(int i=0;i<N;i++)
    {
        int input;
        cin>>input;
        insertAtLast(head,input);
    }
    /*insertAtHead(head,2);
    insertAtHead(head,20);
    insertAtHead(head,21);
    insertAtHead(head,22);
    insertAtHead(head,23);
    insertAtHead(head,24);
    insertAtHead(head,25);
    printLinkedList(head);*/
    node * n=KthReverse(head,K);
    printLinkedList(n);
    return 0;
}
