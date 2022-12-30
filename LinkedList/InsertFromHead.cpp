#include<bits/stdc++.h>
using namespace std;
class node{
    //node will contain 2 things data and a pointer variable of node type to store adress of next node
    public:
    int data;
    node *next;

    node(int data)
    {
        //Generating node with constructor
        this->data=data;
        this->next=NULL;
    }
};
    void insertAtHead(node* &head,int data)
    {
        //we are using &head because we don't want to create copy of head we want to work on that head only

        node* temp=new node(data);//for generating a new Node of data provided by the parameter
        //head is storing the adress of the previous node and we are insertAtHeading from head side and not from tail side so now we want to attach our new node to previous linked list starting point so our new node's next variable should have the adress of the starting node of the linked list which is in head because we know head stores the adress of the first node so we will put adress of the 1st element of the linked list in the new node's next by temp->next=head;
        temp->next=head;
        //now new node has been added so the previous starting node is no more the starting node. Now the starting node is the new temp node we added so now head will store the adress of this temp node so we did head=temp;
        head=temp;
    }
    void insertAtTail(node* &tail,int data)
    {
        node* temp=new node(data);
        tail->next=temp;
        tail=temp;
    }
    void insertAtMiddle(node* &tail,node* &head,int position,int data)
    {
        if(position==0)
        {
            insertAtHead(head,data);
            return;
        }
        node *temp=head;
        int Index_Just_Before_Where_We_Have_To_Place_New_Element=position-1;
        int it=1;
        while(it<=Index_Just_Before_Where_We_Have_To_Place_New_Element)
        {
            temp=temp->next;
            it++;
        }
        if(temp->next==NULL)
        {
            //iska matlab agar last mein insert karna hai to ye hi function use karlo qki agar last mein bina is code ko ke insert karenge to tail update nai ho payega jo ki ek bug hai
            insertAtTail(tail,data);
            return;
        }     
        node* newNode=new node(data);
        newNode->next=temp->next;
        temp->next=newNode;
    }
    void print(node* &head)
    {
     //we are using &head because we don't want to create copy of head we want to work on that head only
       
        node* temp=head;//decalring a temp pointer variable to store the adress of 1st element of the linked list which is present in head and we did this because we don't to mess with actual head;
        while(temp!=NULL)
        {
            // we now the last node's next variable will conatain NULL so when temp variable is NULL then we will stop
        cout<<temp->data<<" ";//this is simple
        temp=temp->next;//each time we will update temp with the adress of next node 
        }
    }
int main()
{
    node* n1=new node(6);
    node* head=n1;//Every linked list have a head and a tail so head will basically store the adress of 1st node so we made n1 as head and tail is the pointer pointing last node of the linked list which is pointing to null at first if there is only 1 element then both head and tail will be the 1st element only;
    node* tail=n1;//Every linked list have a head and a tail so head will basically store the adress of 1st node so we made n1 as head and tail is the pointer pointing last node of the linked list which is pointing to null at first if there is only 1 element then both head and tail will be the 1st element only;

    print(head);
    cout<<"\nAfter insertAtHeadion "<<endl;
    insertAtHead(head,8);
    insertAtHead(head,100);
    insertAtHead(head,21);
    insertAtTail(tail,77);
    insertAtTail(tail,79);
    insertAtHead(head,709);
    insertAtTail(tail,989);
    insertAtMiddle(tail,head,0,-7);
    insertAtMiddle(tail,head,9,8000);
    insertAtMiddle(tail,head,10,100);
    print(head);
    cout<<"\nHead "<<head->data<<endl;
    cout<<"Tail "<<tail->data<<endl;
    return 0;
}