#include <iostream>
using namespace std;

struct Node { //Node structure
    int data;
    Node* next;
};
Node* createNode(int value){
    Node* newNode = new Node(); //Allocate memory
    newNode->data = value;
    newNode->next = nullptr;
    return newNode;
}
void insert(Node* & head, int value){
    Node* newNode = createNode(value);
    if(head == nullptr){ //if list if empty
        head = newNode; // add as first node
        return;
    }
    Node* temp = head; //Initiaze temp to point to begining of list
    while(temp->next != nullptr){ //traverse till end of list - To insert at end
        temp = temp->next;
    }
    temp->next = newNode; //link new node
}

void traverse(Node* head){
    if(head == nullptr){
        cout<<"List is empty \n";
    }
    Node* temp = head;
    while(temp != nullptr){
        cout<<temp->data<<" -> ";
        temp = temp->next;
    }
    cout<<" NULL\n";
    
}

Node* search(Node* head, int value){
    Node* temp = head;
    while(temp!=nullptr){
        if(temp->data == value){
            return temp; //Node found
        }
        temp = temp->next;
    }
    return nullptr; //Node not found
}

void deleteNode(Node*& head, int value){
    if(head==nullptr){
        cout<<"List is empty. Nothing to delete \n";
        return;
    }
    Node* target = search(head, value);
    if(target == nullptr){
        cout<<" Value "<<value<< "not found \n";
        return;
    }
    //handle deleteion of head node
    if(head == target){
        Node* temp = head;
        head = head->next;
        delete temp;
        cout<<"Node with value"<<value<< " deleted \n";
        traverse(head);
        return;
    }

    //find node's predecessor
    Node* predecessor = head;
    while(predecessor->next != target){
        predecessor = predecessor->next;
    }
    //perform deletion
    predecessor->next = target->next;
    delete target;
    cout<<"Node with value "<<value<<" deleted \n";
    traverse(head);

}

int main() {
    Node* head = nullptr; //Initialize list to be empty
    insert(head, 10);
    insert(head, 20);
    insert(head, 30);
    traverse(head);
    int searchValue = 20;
    Node* result = search(head, searchValue);
    if(result){
        cout<<"Node with value "<<searchValue <<" found";
    }else{
        cout<<"Node with value "<<searchValue <<" NOT found";
    }    
    deleteNode(head, 20);
    deleteNode(head, 45); //deleting non-existant node
    return 0;
}