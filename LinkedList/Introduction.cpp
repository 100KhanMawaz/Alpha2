//Linked list is a collection of nodes and each node contaiin data and adress of the other node
//it is a dynamic linear data structure
//elements are stored in non contigious locations and are randomly stored in heap
#include<bits/stdc++.h>
using namespace std;
class node{
    public:
    int data;
    node *next;//The type of this variable pointer is node because it will store node adress. same if want to store integer adress we want integer pointer

    node(int data)
    {
        this->data=data;
        this->next=NULL;
    }
};
int main()
{
    node *n1=new node(6);//we took dynamic method for object where n1 is not the object but n1 is storing the object adress because we want constructor to pass parameters to initialize data
    cout<<n1->data<<endl;
    cout<<n1->next<<endl;
    return 0;
}

