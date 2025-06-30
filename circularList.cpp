#include <iostream>
using namespace std;

// Node structure for circular linked list
struct Node {
    int data;
    Node* next;
};

// Function to create a new node
Node* createNode(int value) {
    Node* newNode = new Node();
    newNode->data = value;
    newNode->next = nullptr; // Default next pointer is nullptr
    return newNode;
}

// Function to insert a node at the beginning
void insertAtBeginning(Node*& head, int value) {
    Node* newNode = createNode(value);
    if (head == nullptr) { // List is empty
        head = newNode;
        newNode->next = head; // Point to itself
        return;
    }
    Node* temp = head;
    while (temp->next != head) { // Traverse to the last node
        temp = temp->next;
    }
    newNode->next = head; // Link new node to current head
    temp->next = newNode; // Link last node to new node
    head = newNode;       // Update head to the new node
}

// Function to insert a node at the end
void insertAtEnd(Node*& head, int value) {
    Node* newNode = createNode(value);
    if (head == nullptr) { // List is empty
        head = newNode;
        newNode->next = head; // Point to itself
        return;
    }
    Node* temp = head;
    while (temp->next != head) { // Traverse to the last node
        temp = temp->next;
    }
    temp->next = newNode; // Link last node to new node
    newNode->next = head; // Link new node to head
}

// Function to search for a value in the list
Node* search(Node* head, int value) {
    if (head == nullptr) { // List is empty
        return nullptr;
    }
    Node* temp = head;
    do {
        if (temp->data == value) {
            return temp; // Node found
        }
        temp = temp->next;
    } while (temp != head);
    return nullptr; // Node not found
}

// Function to delete a node by value
void deleteNode(Node*& head, int value) {
    if (head == nullptr) { // List is empty
        cout << "List is empty. Nothing to delete.\n";
        return;
    }

    // Handle deletion of the only node in the list
    if (head->data == value && head->next == head) {
        delete head;
        head = nullptr;
        cout << "Node with value " << value << " deleted.\n";
        return;
    }

    // Handle deletion of the head node
    if (head->data == value) {
        Node* temp = head;
        Node* last = head;
        while (last->next != head) { // Traverse to the last node
            last = last->next;
        }
        head = head->next;   // Update head to the next node
        last->next = head;   // Update last node's next to new head
        delete temp;         // Delete old head
        cout << "Node with value " << value << " deleted.\n";
        return;
    }

    // Handle deletion of a node other than the head
    Node* current = head;
    Node* prev = nullptr;
    while (current->next != head && current->data != value) {
        prev = current;
        current = current->next;
    }
    if (current->data == value) {
        prev->next = current->next; // Bypass the node
        delete current;             // Delete the node
        cout << "Node with value " << value << " deleted.\n";
    } else {
        cout << "Value " << value << " not found in the list.\n";
    }
}

// Function to traverse and print the circular linked list
void traverse(Node* head) {
    if (head == nullptr) {
        cout << "List is empty.\n";
        return;
    }
    Node* temp = head;
    do {
        cout << temp->data << " -> ";
        temp = temp->next;
    } while (temp != head);
    cout << "(HEAD)\n"; // Indicate circularity
}

// Main function to demonstrate the circular linked list
int main() {
    Node* head = nullptr; // Initialize an empty circular linked list

    // Insert elements
    insertAtEnd(head, 10);
    insertAtEnd(head, 20);
    insertAtEnd(head, 30);
    cout << "Circular Linked List after insertion at the end:\n";
    traverse(head);

    // Insert at the beginning
    insertAtBeginning(head, 5);
    cout << "Circular Linked List after insertion at the beginning:\n";
    traverse(head);

    // Search for a value
    int searchValue = 20;
    Node* foundNode = search(head, searchValue);
    if (foundNode) {
        cout << "Node with value " << searchValue << " found.\n";
    } else {
        cout << "Node with value " << searchValue << " not found.\n";
    }

    // Delete a node
    deleteNode(head, 20);
    cout << "Circular Linked List after deleting 20:\n";
    traverse(head);

    // Attempt to delete a non-existent value
    deleteNode(head, 100);

    // Delete the head node
    deleteNode(head, 5);
    cout << "Circular Linked List after deleting 5:\n";
    traverse(head);

    return 0;
}