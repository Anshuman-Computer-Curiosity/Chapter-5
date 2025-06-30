#include <iostream>
using namespace std;
struct Node{
    int data;
    Node* next;
};
Node* createNode(int value){
    Node* newNode = new Node(); //allocate memory for new node of given structure
    newNode->data = value; //Assign value to data part
    newNode->next = nullptr; //Default next pointer is nullptr
    return newNode;
}
void insertBeg(Node* &head, int value){
    Node* newNode = createNode(value); //creates new node and assigns value
    if(head==nullptr){ //List is empty?
        head = newNode;
        newNode->next = head; //Points to itself
        // cout<<"Node with value "<<value<<" inserted at beginning of the cir. linked list.\n";
        return;
    }
    Node* temp = head;
    while(temp->next != head) { //Traverse to last node
        temp = temp->next;
    }
    newNode->next = head; //Link new node to current head
    temp->next = newNode; //Link last node's next part of new node to maintain circularity
    head = newNode;//update head to new node
    // cout<<"Node with value "<<value<<" inserted at beginning of the cir. linked list.\n";
}
void insertEnd(Node* &head, int value){
    Node* newNode = createNode(value); //creates new node and assigns value
    if(head==nullptr){ //List is empty?
        head = newNode;
        newNode->next = head; //Points to itself
        // cout<<"Node with value "<<value<<" inserted at end of the cir. linked list.\n";
        return;
    }
    Node* temp = head;
    while(temp->next != head) { //Traverse to last node
        temp = temp->next;
    }
    temp->next = newNode; //Link last node's next part to new node
    newNode->next = head; //Link new node's next part to head
    // cout<<"Node with value "<<value<<" inserted at end of the cir. linked list.\n";
}
void traverse(Node* head){
    if(head==nullptr){
        cout<<"List is empty.\n";
        return;
    }
    Node* temp = head;
    do{
        cout<<temp->data<<" -> ";
        temp = temp->next;
    }while(temp!=head);
    cout<<" (Head)\n"; //(optional) to indicate circularity
}

Node* search(Node* head, int value){
    if(head == nullptr){
        return nullptr; // node not found
    }
    Node* temp = head;
    do{
        if(temp->data == value){
            return temp; // Node found and return a pointer to that node
        }
        temp = temp->next; // Otherwise. move to next node
    }while(temp != head);
    return nullptr; // Indicates node not found
}
void deleteNode( Node*& head, int value){
    if(head == nullptr){ //List is empty
        cout<<"List is empty. Nothing to delete. \n";
        return;
    }
    Node* target = search(head, value);
    if(target == nullptr){
        cout<<"Node with value "<<value<<" NOT found.\n";
        return;
    }
    if(head == target && head->next == head){//
        delete head; // free memory
        head = nullptr;
        cout<<"Node with only value "<<value<<" deleted. \n";
         return;
    }

    //handle deletion of only node
    //  head = nullptr; // points to null -  empty cir. list
    //     if(head->data == value && head->next == head){
    //     delete head; // free memory
    //    cout<<"Node with only value "<<value<<" deleted. \n";
    //     return;
    // }
     if(head == target) { //handle deletion of first node
        Node* temp = head;
        Node* last = head;
        while(last->next!=head){ //Traverses to last node
            last = last->next; //move to next node each iteration
        }
        head = head->next; //update head pointer to next node
        last->next = head; //update last node's next/link part to new head
        delete temp;
        cout<<"Node with value "<<value<<" deleted.\n";
        return;
     }
    // //handle deletion of head node
    // if(head->data == value){
    //     Node* temp = head;
    //     Node* last = head;
    //     while(last->next!=head){ //Traverses to last node
    //         last = last->next; //move to next node each iteration
    //     }
    //     head = head->next; //update head pointer to next node
    //     last->next = head; //update last node's next/link part to new head
    //     delete temp;
    //     cout<<"Node with value "<<value<<" deleted.\n";
    //     return;
    // }
   
    //handle deletion of a node other than head node
    // Node* current = head;
    // Node* prev = nullptr;
    Node* prev = head;
    while(prev->next != target){
        prev = prev->next;
    }
    prev->next = target->next; //By pass node
        delete target;
        cout<<"Node with value "<<value<<" deleted from cir. linked list.\n";
    
    // while(current->next != head && current->data != value){
    //         prev = current; //update prev pointer
    //         current = current->next; //update current pointer
    // }
    // if(current->data == value){
    //     prev->next = current->next; //By pass node
    //     delete current;
    //     cout<<"Node with value "<<value<<" deleted from cir. linked list.\n";
    // }else{
    //     cout<<"Node with value "<<value<<" NOT found in cir. linked list.\n";
    // }

}

// Main function to demonstrate the circular linked list
int main() {
    Node* head = nullptr; //Empty circular linked list
    
    insertBeg(head,10);
    insertBeg(head,5);
    insertEnd(head,20);
    traverse(head);

    int searchValue = 40;
    Node* foundNode = search(head, searchValue);
    if(foundNode){
        cout<<" Node with value "<<searchValue<<" found in cir. linked list.\n";
    }else{
        cout<<" Node with value "<<searchValue<<" NOT found in cir. linked list.\n";
    }
    deleteNode(head, 5);
    deleteNode(head, 45);
    return 0;
}