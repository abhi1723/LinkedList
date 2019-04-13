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
void insertionAtHead(node* &head,int data){
    node *n=new node(data);
    if(head==NULL) head=n;
    else {
        n->next=head;
        head=n;
    }
}
void printLinkedList(node* head){
    while(head!=NULL){
        cout<<head->data<<endl;
        head=head->next;
    }
}
int main()
{
    node* head=NULL;
    insertionAtHead(head,5);
    insertionAtHead(head,17);
    insertionAtHead(head,3);
    insertionAtHead(head,25);
    printLinkedList(head);
    return 0;
}
