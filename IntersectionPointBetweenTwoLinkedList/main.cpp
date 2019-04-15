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
int searchInTheList(node* head1,node *head2){
    while(head2!=NULL){
        if(head1->data==head2->data)
        return 1;
        head2=head2->next;
    }
    return -1;
}
int main()
{
    node* head1=NULL,*head2=NULL;
    int N1,N2;
    cin>>N1;
    for(int i=0;i<N1;i++)
    {
        int input;
        cin>>input;
        insertAtLast(head1,input);
    }
    cin>>N2;
    for(int i=0;i<N2;i++)
    {
        int input;
        cin>>input;
        insertAtLast(head2,input);
    }
    int foundOrNotFound=-1;
    while(head1!=NULL){
        foundOrNotFound=searchInTheList(head1,head2);
        if(foundOrNotFound==1){
            cout<<head1->data;
            break;
        }
        head1=head1->next;
    }
    if(foundOrNotFound==-1)
        cout<<foundOrNotFound;
    return 0;
}
