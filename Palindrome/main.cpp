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
    cout<<endl;
}
node* reverseLinkedList(node* head){
    node *current=head,*next=NULL,*prev=NULL;
    while(current!=NULL){
        next=current->next;
        current->next=prev;
        prev=current;
        current=next;
    }
    return prev;
}
bool checkPalindrome(node* head,node* reversedList){
    while(head!=NULL){
        if(head->data!=reversedList->data){
            return false;
        }
        head=head->next;
        reversedList=reversedList->next;
    }
    return true;
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
    //printLinkedList(head);
    node* reversedList=reverseLinkedList(head);
    bool check=checkPalindrome(head,reversedList);
    cout<<check;
    //printLinkedList(reversedList);
    return 0;
}
