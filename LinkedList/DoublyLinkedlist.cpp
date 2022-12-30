#include<bits/stdc++.h>
using namespace std;
class node{

    public:
    int data;
    node *next;
    node *previous;
    node(int data)
    {
        this->data=data;
        this->next=NULL;
        this->previous=NULL;
    }

};
void insertFromHead(node* &head,int data)
{
    node* temp=new node(data);
    temp->next=head;
    head->previous=temp;
    head=temp;
}
void insertFromTail(node* &tail,int data)
{
    node* temp=new node(data);
    temp->previous=tail;
    tail->next=temp;
    tail=temp;
}
void print(node* &head)
{
    node* temp=head;
    while(temp!=NULL)
    {
        cout<<temp->data<<" "<<endl;
        temp=temp->next;
    }
}
int size(node* &head)
{
    node* temp=head;
    int cnt=0;
    while(temp!=NULL)
    {
        cnt++,
        temp=temp->next;
    }
    return cnt;
}
void insertAtMiddle(node* &head,node* &tail,int position,int data){
    if(position==1)
    {
        insertFromHead(head,data);
        return;
    }
    if(position==size(head))
    {
        insertFromTail(tail,data);
        return;
    }
    node* temp=head;
    int cnt=1;
    while(cnt<position-1)
    {
        temp=temp->next;
        cnt++;
    }
    node* newNode=new node(data);
    newNode->next=temp->next;
    newNode->previous=temp;
    temp->next=newNode;
}
void deleteFromHead(node* &head)
{
    node* temp=head;
    temp->next->previous=NULL;
    head=temp->next;
    temp->next=NULL;
    delete temp;
}
void deleteFromTail(node* &tail)
{
    node* temp=tail;
    tail=temp->previous;
    temp->previous->next=NULL;
    delete temp;
}
void deleteFromMiddle(node* &head,node* &tail,int position)
{
    int cnt=1;
    node* temp=head;
    while(cnt<position)
    {
        temp=temp->next;
        cnt++;
    }
    temp->previous->next=temp->next;
    temp->next->previous=temp->previous;
    temp->next=NULL;
    temp->previous=NULL;
    
    delete temp;
}
int main(){
    node* n1=new node(786);
    node* head=n1;
    node* tail=n1;
    
    insertFromHead(head,76);
    insertFromHead(head,65);
    insertFromHead(head,9);
    insertFromHead(head,99);
    insertFromTail(tail,51);
    insertAtMiddle(head,tail,6,100);
    deleteFromHead(head);
    deleteFromTail(tail);
    deleteFromMiddle(head,tail,4);
    print(head);
  //  cout<<size(head)<<endl;
     cout<<"\nHead "<<head->data<<endl;
    cout<<"Tail "<<tail->data<<endl;
    return 0;
}