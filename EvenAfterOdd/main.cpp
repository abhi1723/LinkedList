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
void evenAfterOdd(node *&head){
    node * start=head;
    node *temp=head;
    node *even=NULL,*odd=NULL,*startEven=NULL,*startOdd=NULL;
    while(temp!=NULL){
            if((temp->data)%2==0){
                if(even==NULL){
                    startEven=temp;
                    even=temp;
                }
                else {
                    even->next=temp;
                    even=temp;
                }
            }
            else {
                if(odd==NULL){
                    startOdd=temp;
                    odd=temp;
                }
                else {
                    odd->next=temp;
                    odd=temp;
                }
            }
        temp=temp->next;
    }
    if(startOdd!=NULL)
    head=startOdd;
    else
        head=startEven;
    if(odd!=NULL)
    odd->next=startEven;
    if(even!=NULL)
    even->next=NULL;
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
    evenAfterOdd(head);
    printLinkedList(head);
    return 0;
}
