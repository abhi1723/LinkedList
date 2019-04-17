#include <iostream>
#define lint long long int
using namespace std;
class node{
public:
    lint data;
    node *next;
    node(lint d){
        data=d;
        next=NULL;
    }
};
void prlintLinkedList(node *head){
    while(head!=NULL){
        cout<<head->data<<" ";
        head=head->next;
    }
    cout<<endl;
}
void insertAtLast(node* &head,lint data){
    node* n=new node(data);
    if(head==NULL) head=n;
    else{
            node *temp=head;
            while(temp->next!=NULL)
                temp=temp->next;
            temp->next=n;
    }
}
node* mergeTwoLists(node* head1,node* head2){
    node* start=NULL,*temp=NULL;
    while(head1!=NULL && head2!=NULL){
         //  cout<<"head1 "<<head1->data<<endl;
        //cout<<"head2 "<<head2->data<<endl;
        if(head1->data>head2->data){
            if(start==NULL)
                {start=head2;temp=head2;}
            else{
                start->next=head2;
                start=head2;
            }
            head2=head2->next;
        }
        else {
            if(start==NULL)
                {start=head1;temp=head1;}
            else{
                start->next=head1;
                start=head1;
            }
            head1=head1->next;
        }
    }
    while(head1!=NULL){
        start->next=head1;
        start=head1;
        head1=head1->next;
    }
    while(head2!=NULL){
        start->next=head2;
        start=head2;
        head2=head2->next;
    }
    return temp;
}
int main()
{
    lint N1,N2,T;
    cin>>T;
    node* mergedList[T];
    for(lint k=0;k<T;k++){
    node* head1=NULL,*head2=NULL;
    cin>>N1;
    for(lint i=0;i<N1;i++)
    {
        lint input;
        cin>>input;
        insertAtLast(head1,input);
    }
    cin>>N2;
    for(lint i=0;i<N2;i++)
    {
        lint input;
        cin>>input;
        insertAtLast(head2,input);
    }
    if(N1==0)
        mergedList[k]=head2;
    else if(N2==0)
        mergedList[k]=head1;
    else
    mergedList[k]=mergeTwoLists(head1,head2);
    }
    for(lint i=0;i<T;i++)
    prlintLinkedList(mergedList[i]);
    return 0;
}
