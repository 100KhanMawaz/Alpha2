#include<bits/stdc++.h>
using namespace std;
class node{
    public:
    int data;
    node* next=NULL;
    node(int d){
        data=d;
        next=NULL;
    }
};
 void SearchAndInsert(node* &tail,int SearchingElement,int data)
    {
        //Search That element and place just next to it if not available then place at last;
            node* newNode= new node(data);
        if(tail==NULL)
        {
            //Matlab linkedlist hai hi nai New Linked List banega so we don't need to search any element we will just put 1st element
            tail=newNode;
            tail->next=tail;
        }
        else{
            node* temp=tail;
            while(temp->data!=SearchingElement && temp->next!=tail)
            {
                //Conditions for loop are
                /*
                1> jab tak searching element ni milega tab tak badhte raho
                2> temp->next will point 1st element because temp=tail and tail is last element who's next is poiinting to 1st element if tail is the only element then the loop will not execute because temp->next will be equal to tail and if tail is not the only element then loop will iterate from tail to tail-1
                */
               temp=temp->next;

            }
            //loop will terminate if either element is found or if whole array is traversed and element not found.
            if(temp->next==tail)
            {
                //cout<<temp->data<<endl;
                //iska matlab hai last mein insert karre qki ya to ek hi element hai ya to searching element maujood nahi hai or hmlg last mein place karre
            newNode->next=temp->next;
            temp->next=newNode;
            tail=newNode;
            }
            else{
            newNode->next=temp->next;
            temp->next=newNode;
            }
        }
    }
    void deleteNode(node* &tail,int SearchingElement)
    {
        node* temp=tail;
        //Using below loop we will find previous element from the element to delete
        while(temp->next->data!=SearchingElement)
        {
            temp=temp->next;
        }
        node* previousElement=temp;
        node* currentElement=temp->next;
        previousElement->next=currentElement->next;
        currentElement->next=NULL;
        if(tail->data==SearchingElement)
        {
         //IF deleting element is the tail element then make the previous element as tail ;
        if(tail->next==NULL){
        tail=NULL;
        return;
        }
        tail=previousElement;
        }
        delete currentElement;
    }
    void print(node* &tail)
    {
        node* temp=tail;
        if(temp==NULL){
        cout<<"List is EMpty"<<endl;
        return;
        }
        cout<<tail->data<<" ";
        while(temp->next!=tail)
        {
            temp=temp->next;
            cout<<temp->data<<" ";
        }
        
    }
int main()
{
   node* tail=NULL;
    SearchAndInsert(tail,3,5);
    SearchAndInsert(tail,3,7);
    // SearchAndInsert(tail,3,9);
    // SearchAndInsert(tail,7,2);
    deleteNode(tail,7);
    print(tail);
    cout<<"tail karo "<<tail->data<<endl;
    return 0;
}