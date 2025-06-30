#include <iostream> 
using namespace std; 
// Node structure for doubly linked list 
struct Node { 
    int data; 
    Node* flink; 
    Node* plink; 
}; 
// Function to create a new node 
Node* createNode(int value) { 
    Node* newNode = new Node(); 
    newNode->data = value; 
    newNode->flink = nullptr; 
    newNode->plink = nullptr; 
    return newNode; 
} 
// Function to insert a node at the beginning 
void insertAtBeginning(Node*& head, Node*& tail, int value) { 
    Node* newNode = createNode(value); 
    if (head == nullptr) { // List is empty 
    head = tail = newNode; 
    return; 
    } 
    newNode->flink = head; 
    head->plink = newNode; 
    head = newNode; 
} 
// Function to insert a node at the end 
void insertAtEnd(Node*& head, Node*& tail, int value) { 
    Node* newNode = createNode(value); 
    if (head == nullptr) { // List is empty 
    head = tail = newNode; 
    return; 
    } 
    tail->flink = newNode; 
    newNode->plink = tail; 
    tail = newNode; 
} 
// Function to search for a value in the list 
Node* search(Node* head, int value) { 
    Node* temp = head; 
    while (temp != nullptr) { 
        if (temp->data == value) { 
            return temp; // Node found 
        } 
        temp = temp->flink; 
    } 
    return nullptr; // Node not found 
} 
// Function to delete a node by value 
void deleteNode(Node*& head, Node*& tail, int value) { 
    if (head == nullptr) { // List is empty 
        cout << "List is empty. Nothing to delete.\n"; 
        return; 
    } 
    Node* target = search(head, value);
    // Node* temp = head; 
    // while (temp != nullptr && temp->data != value) { 
    //     temp = temp->flink; 
    // } 
    if (target == nullptr) { 
        cout << "Value " << value << " not found in the list.\n"; 
        return; 
    } 
    if (target->plink != nullptr) { 
        target->plink->flink = target->flink; 
    } else { 
        head = target->flink; // Update head if needed 
    } 
    if (target->flink != nullptr) { 
        target->flink->plink = target->plink; 
    } else { 
        tail = target->plink; // Update tail if needed 
    } 
    delete target; 
    cout << "Node with value " << value << " deleted.\n"; 
} 
// Function to traverse and print the doubly linked list 
void traverse(Node* head) { 
    if (head == nullptr) { 
        cout << "List is empty.\n"; 
        return;
    } 
    Node* temp = head; 
    while (temp != nullptr) { 
        cout << temp->data << " -> "; 
        temp = temp->flink;
    } 
    cout << "null\n"; // End of the list 
} 
// Main function to demonstrate the doubly linked list 
int main() { 
    Node* head = nullptr; // Initialize an empty doubly linked list 
    Node* tail = nullptr; // Initialize the tail pointer // Insert elements 
    insertAtEnd(head, tail, 10); 
    insertAtEnd(head, tail, 20); 
    insertAtEnd(head, tail, 30); 
    cout << "Doubly Linked List after insertion at the end:\n"; 
    traverse(head); 
    // Insert at the beginning 
    insertAtBeginning(head, tail, 5); 
    cout << "Doubly Linked List after insertion at the beginning:\n"; traverse(head); 
    // Search for a value 
    int searchValue = 20; 
    Node* foundNode = search(head, searchValue); 
    if (foundNode) { 
        cout << "Node with value " << searchValue << " found.\n"; 
    } else { 
        cout << "Node with value " << searchValue << " not found.\n";
    } 
    // Delete a node 
    deleteNode(head, tail, 20);
    cout << "Doubly Linked List after deleting 5:\n";
    traverse(head);

    return 0;
}
