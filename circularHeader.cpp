#include <iostream>
using namespace std;

// Define the structure of a node
struct Node {
    int data;       // Data part of the node
    Node* next;     // Pointer to the next node
};
Node* createNode(int value){
    Node* newNode = new Node(); //Allocate memory
    newNode->data = value;
    newNode->next = nullptr;
    return newNode;
}
Node* createHeader(){
    Node* header = new Node(); // Header node structure same as node
    header->data = -1; //Assign some dummy value
    header->next = header; //Points to itself
    return header;
}
void insertBeg(Node* header, int value){
    Node* newNode = createNode(value);
    newNode->next = header->next; 
    header->next = newNode;
    // cout<<"Node with value "<<value<<" inserted at beg. of cir. header linked list.\n";
}
void insertEnd(Node* header, int value){
    Node* newNode = createNode(value); 
    //Traverse to end
    Node* temp = header; // intialize to start of list
    while(temp->next != header){
        temp = temp->next;//Move to next node
    }
    temp->next = newNode; // Link last node to new node
    newNode->next = header; //Link new node to header
    // cout<<"Node with value "<<value<<" inserted at end of cir. header linked list.\n";
}
void traverse(Node* header){
    if(header->next == header){ // heade node points to itself
        cout<<" List is empty.";
    }
    Node* temp = header->next; //Start with first node
    while(temp != header){//Unless points back to itself
        cout<<temp->data<<" -> ";
        temp = temp->next; //move to next node
    }
    cout<<"(Header)\n"; //to indicate circularity
}
Node* search(Node* header, int value){
    Node* temp = header->next; //Start with first actual node
    while(temp != header){
        if(temp->data == value){
            return temp; //Node found
        }
        temp = temp->next; //Move to next node
    }
    return nullptr; //Node not found
}
void deleteNode(Node* header, int value){
    if(header->next == nullptr){
        cout<<"List is empty.\n";
        return;
    }
    Node* target = search(header, value);
    if(target == nullptr){
        cout<< "Node with value "<<value<<" Not present.\n";
    }
    Node* prev = header;
    while(prev->next != target){ // finds the predecssor node
        prev = prev->next;
    }
    prev->next =  target->next; //By pass target
    delete target; // free memory for target
    cout<<"Node with value "<<value<< " deleted.\n";
}


// Main function to test the circular header linked list
int main() {
    Node* header = createHeader();
    
    insertBeg(header, 10);
    insertEnd(header, 20);
    int searchValue = 40;
    Node* foundNode = search(header,searchValue);
    if(foundNode){
        cout<<"Node with value "<<searchValue<<" found in cir. header linked list.\n";
    }else{
        cout<<"Node with value "<<searchValue<<" NOT found in cir. header linked list.\n";
    }
    deleteNode(header, 30);
    traverse(header);
    return 0;
}