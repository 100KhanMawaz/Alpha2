#include<bits/stdc++.h>
using namespace std;
class node{

    public:
    int data;
    node *next;
    node(int data)
    {
        this->data=data;
        this->next=NULL;
    }

};
void insertFromTail(node* &tail,int data){

    node *temp=new node(data);
    tail->next=temp;
    tail=temp;
}
void print(node* &head)
{
  //  node* temp=head;
    for(node* temp=head;temp!=NULL;temp=temp->next)
    cout<<temp->data<<" ";
}
void deleteNode(node* &head,node* &tail,int position)
{
    if(position==1)
    {
        node *toDelete=head;
        head=head->next;
        delete toDelete;
        return;
    }
    node* temp=head;
    int cnt=1;
    while(cnt<position-1)
    {
        temp=temp->next;
        cnt++;
    }
    node* previous=temp;
    //ab 2 aage badhenge previous se
    temp=temp->next;//ek baar
    node *toDelete=temp;
    if(temp->next==NULL)
    {
        //Matlab jab last element delete hora hai tab ka case hai ye
        //last element mein tail ko handle krna hoga
        tail=previous;

    }
    previous->next=temp->next;//dusra baar badhe or previous->next mein daal bhi simoultaneously.
    delete toDelete;
}
int main()
{
    node *n1=new node(5);
    node *head=n1;
    node *tail=n1;
    for(int i=4;i>0;i--)
    insertFromTail(tail,i);
    print(head);
    cout<<endl;
    deleteNode(head,tail,5);
    print(head);
    cout<<endl;
    cout<<"Head "<<head->data<<endl;
    cout<<"tail "<<tail->data<<endl;
    
    return 0;
}