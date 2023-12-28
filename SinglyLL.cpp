#include<iostream>
using namespace std;

class Node
{
    public:

    int data;
    Node* next;

    //Constructing the node
    Node(int data)
    {
        this->data = data;
        this-> next = NULL;
    }

    //Destructor
    ~Node()
    {
         int val = this-> data;

        if(this -> next != NULL)
        {
            delete next;
            this -> next = NULL;
        }
        cout<<"Memory is free from node with data "<<val<<endl;
    }
};

void insertAtHead( Node* &head, int d)
{
    Node* temp = new Node(d);

    temp-> next = head;
    head = temp;

}

void insertAtTail(Node* &tail, int d)
{
    Node* temp = new Node(d);

    tail-> next = temp;

    tail = temp;
}

void insertAtPosition(Node* &tail, Node* &head, int position, int d)
{
    //Inserting at start
    if(position == 1)
    {
        insertAtHead(head, d);
        return;
    }
    Node* temp = head;
    int cnt = 1;

    while(cnt < position -1)
    {
        temp = temp -> next;
        cnt++;
    }

    //Inserting at tail

    if(temp->next == NULL)
    {
        insertAtTail(tail, d);
        return;
        
    }

    Node* nodeToInsert = new Node(d);

   nodeToInsert->next = temp->next;
   temp->next = nodeToInsert; 
}

void deleteNode(int position, Node* &head, Node* &tail)
{
    //If deletion is at start
    if(position == 1)
    {
        Node* temp = head;

        head = head->next;
        temp->next = NULL;

        delete temp;
    }

    else{
        Node* curr = head;
        Node* prev = NULL;

        int cnt = 1;
        while(cnt < position)
        {
            prev = curr;
            curr = curr->next;
            cnt++;
        }

        //If deletion is at tail
        if(curr -> next == NULL)
        {
            prev->next = curr->next;
            curr->next = NULL;
            tail = prev; //Updating the tail after deletion
            delete curr; 
        }
        else{
            prev->next = curr->next;
            curr->next = NULL;
            delete curr;

        }
        
    }
}

//Traversing the list
void print(Node* &head)
{
    Node* temp = head;

    while(temp!= NULL)
    {
        cout<<temp->data<<" ";
        temp = temp->next;
    }

    cout<<endl;
}

int main()
{
    Node* node1 = new Node(10);

    Node* head = node1;
    Node* tail = node1;

    //print(head);
    insertAtHead(head,12);

    //print(head);

    insertAtTail(tail, 15);

    //print(head);

    insertAtPosition(tail, head, 4, 22);

    cout<<"Before deletion: "<<endl;
    print(head);

    cout<<"Head "<< head->data<<endl;
    cout<<"Tail "<<tail->data<<endl;

    deleteNode(4, head, tail);

    cout<<"After deletion"<<endl;
    

     print(head);

    cout<<"Head "<< head->data<<endl;
    cout<<"Tail "<<tail->data<<endl;



}