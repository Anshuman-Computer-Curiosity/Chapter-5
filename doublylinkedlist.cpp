#include <iostream> 
using namespace std; 
struct Node{ //Node structure for doubly linked list
    int data; // data part
    Node* flink; //forward link
    Node* plink; //link to previous node 
};

Node* createNode(int value){
    Node* newNode = new Node(); //Allocate memory same as Node structure
    newNode->data = value;
    newNode->flink = nullptr;
    newNode->plink = nullptr;
    return newNode;
}
void insertBeg(Node*& head, Node*& tail, int value){
    Node* newNode = createNode(value); //create a new node of doubly linked list with given value
    if(head == nullptr){ //List is empty
        head = tail = newNode; //Add new node as the only node
        cout<<"Node with value "<<value<<" inserted at beginning of doubly linked list.\n";
        return;
    }
    newNode->flink = head; //Link new node's flink pointer to point to same node as head
    head->plink = newNode; //Link plink of first node to point to new node
    head = newNode; // head now points to new first node
    cout<<"Node with value "<<value<<" inserted at beginning of doubly linked list.\n";
}

void insertEnd(Node*& head, Node*& tail, int value){
    Node* newNode = createNode(value); //create a new node of doubly linked list with given value
    if(tail == nullptr){ //List is empty
        head = tail = newNode; //Add new node as the only node
        cout<<"Node with value "<<value<<" inserted at end of doubly linked list.\n";
        return;
    }
    tail->flink = newNode; //Link flink of last node to point to new node
    newNode->plink = tail; //Link previous link of new node point to same node tail is pointing
    tail = newNode; // tail now points to new last node
    cout<<"Node with value "<<value<<" inserted at end of doubly linked list.\n";
}
void traverse(Node* head){ //traverse in forward direction
    if(head == nullptr){
        cout<<"List is empty.\n";
        return;
    }
    Node* temp = head; //begin traversal from same node as head is pointing
    while(temp!=nullptr){ // traverse at the end
        cout<<temp->data <<" -> ";
        temp = temp->flink;
    }
    cout<<"(Null)\n"; //Optional, to indicate end of list
}
Node* search(Node* head, int value){
    Node* temp = head; //set first node as current node
    while(temp!=nullptr){
        if(temp->data == value){
            return temp; //Node found
        }
        temp = temp->flink; //Move to next node
    }
    return nullptr; //Node not found in entire list
}
void deleteNode(Node*& head, Node*& tail, int value){
    if(head == nullptr){ //List is empty
        cout<<"List is empty. Nothing to delete \n";
        return;
    }
    Node* target = search(head, value); //search for node with given value
    if (target == nullptr)    {
        cout<<"Value "<<value<< " not found in the list.\n";
        return;
    }
    if(target->plink == nullptr){ //if first node
        head = target->flink; //Update head if needed
    }else{
        target->plink->flink = target->flink; //By pass target
    }
    if(target->flink == nullptr){ //if last node
        tail = target->plink; // update tail if needed
    }else{
        target->flink->plink = target->plink; //By pass target 
    }
    delete target; //free memory
    cout<<"Node with value "<<value<<" deleted.\n";
}


// Main function to demonstrate the doubly linked list 
int main() { 
    Node* head = nullptr; //Initialize head pointer of empty list
    Node* tail = nullptr; //Initialize tail pointer of empty list
    insertBeg(head, tail, 10);
    insertEnd(head, tail, 20);
    traverse(head); // traverse in forward direction
    int searchValue = 20;
    Node* target = search(head, searchValue);
    if(target){
        cout<<"Node with value "<<searchValue<<" found in the doubly linked list.\n";
    }else{
        cout<<"Node with value "<<searchValue<<" NOT found in the doubly linked list.\n";
    }
    deleteNode(head, tail, 20);
    traverse(head);

    return 0;
}
