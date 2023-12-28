#include<iostream>
using namespace std;

class Node{

    public:
    int data;
    Node* next;
    Node* prev;

    //Creating a Node
    Node(int data) 
    {
        this->data = data;
        this->next = NULL;
        this->prev = NULL;
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

void insertAtHead(Node* &head,Node* & tail, int d)
{
    if(head == NULL)
    {
        Node* temp = new Node(d);

        head = temp;
        tail = temp;
    }

    else{
         Node* temp = new Node(d);

        temp -> next = head;
        head -> prev = temp;
        head = temp;
    }
    
       
 
  
}

void insertAtTail(Node* &head, Node* &tail, int d)
{
    if(tail == NULL)
    {
        Node* temp = new Node(d);
        tail = temp;
    }
    else{
            Node* temp = new Node(d);

            tail -> next = temp;
            temp -> prev = tail;
            tail = temp;
    }
    

}

void insetAtPosition(Node* &head, Node* &tail, int position, int d)
{
    if(position == 1)
    {
        insertAtHead(head, tail, d);
        return;
    }
    Node* temp = head;
    int cnt = 1;

    while(cnt < position -1)
    {
        temp = temp-> next;
        cnt++;
    }

    //Inserting at last position 

    if(temp ->next == NULL)
    {
        insertAtTail(head, tail, d);
        return;
    }

    //Inserting at position 

    Node* nodeToInsert = new Node(d);

    nodeToInsert -> next = temp -> next;
    temp -> next -> prev = nodeToInsert;
    temp -> next = nodeToInsert;
    nodeToInsert -> prev = temp;
}

void deleteNode(Node* &head,Node* &tail,  int position)
{
    //If deletion is at start
    if(position == 1)
    {
        Node* temp = head;
        temp -> next -> prev = NULL;
        head = temp -> next;
        temp -> next = NULL;
        delete temp;
    }

    //deletion at last or between nodes
    else{
        Node* curr= head;
        Node* prev = NULL;

        int cnt = 1;

        while(cnt < position)
        {
            prev = curr;
            curr = curr-> next;
            cnt++;

        }
        //if deletion at tail
        if(curr->next == NULL)
        {
            curr->prev = NULL;
            prev -> next = curr->next;
            curr->next = NULL;
            tail = prev; //Updating the tail
            delete curr; 
        }
        else{
            curr->prev = NULL;
            prev -> next = curr->next;
            curr->next = NULL;
            delete curr;
        }
        

    }
}

//Traversing the list
void print(Node* &head)
{
    Node* temp = head;

    while(temp != NULL)
    {
         cout<<temp->data<<" ";
        temp = temp->next;
    }

    cout<<endl;
}

int main()
{
    //Node* node1 = new Node(10);

    /*Here, We have pointed everything to NUll at start
    you can also go with the Node* node1 = new Node(10);*/
    Node* head = NULL;
    Node* prev = NULL;
    Node* tail = NULL;


    //Insert data at head

    insertAtHead(head,tail,  20);   
    insertAtHead(head,tail,  30);   
    insertAtHead(head, tail,  40);  

    //print(head); 

    insertAtTail(head, tail, 10);
    //print(head);

    insetAtPosition(head, tail, 5, 1);
    //print(head);

    cout<<"Befoe delete: "<<endl;
    print(head);
    cout<<"head: "<<head->data<<endl;
    cout<<"Tail: "<<tail->data<<endl;

    deleteNode(head, tail, 4);

    cout<<"After deletion: "<<endl;
    print(head);
    cout<<"head: "<<head->data<<endl;
    cout<<"Tail: "<<tail->data<<endl;

}