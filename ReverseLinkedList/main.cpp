#include <iostream>

using namespace std;
class node {
public:
    int data;
    node* next;
    node(int d){
        data=d;
        next=NULL;
    }
};
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
    while(head!=NULL){
        cout<<head->data<<" ";
        head=head->next;
    }
    cout<<endl;
}
node* reverseLinkedList(node *head){
    if(head==NULL || head->next==NULL) return head;
    node *n=reverseLinkedList(head->next);
    head->next->next=head;
    head->next=NULL;
    return n;
}
int main()
{
    node *head=NULL;
    insertAtLast(head,4);
    insertAtLast(head,44);
    insertAtLast(head,45);
    insertAtLast(head,46);
    insertAtLast(head,47);
    printLinkedList(head);
    node *reversedNode=reverseLinkedList(head);
    printLinkedList(reversedNode);
    return 0;
}
