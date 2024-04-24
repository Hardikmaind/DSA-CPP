#include <bits/stdc++.h> 
using namespace std;
class Node{
    public:
    int data;
    Node* next;
    Node(int val,Node* nextnode=nullptr){
        data=val;
        next=nextnode;
    }
};  
int main()
{


    //M-I
    // Node* head=new Node(10);
    // Node* temp1=new Node(20);
    // Node* temp2=new Node(30);
    // head->next=temp1;
    // temp1->next=temp2;




//    M-II
// //    i can also initialize the linked list like this
//     Node* head=new Node(10,new Node(20,new Node(30)));
//     Node* temp1=head->next;
//     Node* temp2=temp1->next;


    //and also like this
    // M-III 
     
    Node* temp2 = new Node(30);
    Node* temp1 = new Node(20, temp2);
    Node* head = new Node(10, temp1);

   Node* demo=head;

    while(demo!=nullptr){
        cout<<demo->data<<" ";
        demo=demo->next;
    }
     // Free allocated memory
    delete head;
    delete temp1;
    delete temp2;

    return 0;
}
 