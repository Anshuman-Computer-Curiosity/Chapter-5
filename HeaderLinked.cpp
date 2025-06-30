#include <iostream>
using namespace std;
struct Node { //declare structure of a node
    int data; //data part
    Node* next; //Pointer to the next node
};

Node* createNode(int value){
    Node* newNode = new Node(); //Allocate memory
    newNode->data = value; //Assign data
    newNode->next = nullptr; //Initialize next to nullptr
    return newNode;
}

Node* createHeaderList(){
    Node* header = new Node; //Create header node - Allocate memory same as Node
    header->data = 0;
    header->next = nullptr;
    return header;
}
void insertEnd(Node* head, int value){
    Node* newNode = createNode(value);
    Node* temp = head; //Start from header node
    while(temp->next != nullptr){ //traverse to last node
        temp = temp->next; //Move to the next node
    }
    temp->next = newNode; //Link new node
    // cout<<"Inserted "<< value << " at the end of the linked list.\n";
}

void insertBeg(Node* head, int value){
    Node* newNode = createNode(value);//Allocate memory
    newNode->next = head->next; //Link new node to first data node
    head->next = newNode;
    // cout<<"Inserted "<< value << " at the begining of the linked list.\n";
}

void traverse(Node* head){
    if(head->next == nullptr){//Check if the list is empty
        cout<<"List is empty. \n";
        return;
    }
    Node* temp = head->next; //skip header node
    while(temp != nullptr){
        cout<< temp->data<<" -> ";
        temp = temp->next;
    }
    cout<<"Null\n";
}

Node* search(Node* head, int value){
    Node* temp = head->next; //skip header node
    while(temp!=nullptr){
        if(temp->data == value){
            return temp; //Node found
        }
        temp = temp->next; //Move to next next
    }
    return nullptr; //Node not found
}

void deleteNode(Node* head, int value){
    if(head->next == nullptr){ //check if list is empty (excluding header)
        cout<<"List is empty. Nothing to delete\n";
        return;
    }
    Node* target = search(head, value);
    if(target == nullptr){
        cout<<"Value "<< value << "NOT found.\n";
        return;
    }
    //locate predecessor node
    Node* predecessor = head; //Start with header node
    while(predecessor->next != target){
        predecessor = predecessor->next;
    }
    //Delete the target node
    predecessor->next = target->next;
    delete target; //free memory 
    cout<<"Node with value "<<value<<" deleted. \n";
    traverse(head);
}
// Main function
int main() {
    Node* head = createHeaderList();
    
    insertEnd(head,10);
    insertEnd(head,20);
    insertEnd(head,30);
    
    insertBeg(head,5);
    insertBeg(head,2);
    int searchValue = 45;
    Node* result = search(head, searchValue);
    if(result){
        cout<<" Node with value "<<searchValue<<" found.\n";
    }else{
        cout<<" Node with value "<<searchValue<<" NOT found.\n";
    }
    deleteNode(head,20);
    deleteNode(head,45);//Deleting non-existant node

    return 0;
}