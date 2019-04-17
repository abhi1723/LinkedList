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
void printLinkedList(node *head){
    while(head!=NULL){
        cout<<head->data<<" ";
        head=head->next;
    }
}

void insertAtLast(node* &head,int data){
    node* n=new node(data);
    node *a=NULL,*b=NULL;
    if(head==NULL) head=n;
    else{
            node *temp=head;
            while(temp!=NULL)
                {
                    if(temp->data==data){
                        a=temp;
                        break;
                    }
                    temp=temp->next;
                }
            node *b=head;
            while(b->next!=NULL){
                b=b->next;
            }
            if(a!=NULL)
            b->next=a;
            else b->next=n;
    }
    //printLinkedList(head);
}
void cycleDetectionAndRemoval(node *&head){
    node* prev=NULL;
    node *fast=head,*slow=head;
    int dummy=1;
    while(dummy==1){
        fast=fast->next->next;
        slow=slow->next;
         if(fast->data==slow->data)
            dummy=2;
    }
    //cout<<"meet at "<<fast->data<<endl;
    slow=head;
    while(slow->data!=fast->data){
        prev=fast;
        slow=slow->next;
        fast=fast->next;
    }
    //cout<<"Cycle at "<<fast->data;
    prev->next=NULL;
    //printLinkedList(head);
}
int main()
{
    node *head=NULL;
    int input;
    cin>>input;
    while(input!=-1)
    {
        insertAtLast(head,input);
        cin>>input;
    }
    //cout<<"hy"<<endl;
    cycleDetectionAndRemoval(head);
    printLinkedList(head);
    return 0;
}
