#include <iostream>
using namespace std;

// Define the structure of a node
struct Node {
    int data;
    Node* next; // Pointer to the next node
};

// Function to create a new node
Node* createNode(int value) {
    Node* newNode = new Node(); // Allocate memory
    newNode->data = value;      // Assign data
    newNode->next = nullptr;    // Initialize next to nullptr
    return newNode;
}

// Function to insert a new node at the end of the list
void insert(Node*& head, int value) {
    Node* newNode = createNode(value);
    if (head == nullptr) { // If the list is empty
        head = newNode;
        return;
    }
    Node* temp = head;
    while (temp->next != nullptr) { // Traverse to the last node
        temp = temp->next;
    }
    temp->next = newNode; // Link the new node
}

// Function to traverse the linked list and print its elements
void traverse(Node* head) {
    if (head == nullptr) {
        cout << "List is empty.\n";
        return;
    }
    Node* temp = head;
    while (temp != nullptr) {
        cout << temp->data << " -> ";
        temp = temp->next;
    }
    cout << "NULL\n";
}

// Function to search for a node with a specific value
Node* search(Node* head, int value) {
    Node* temp = head;
    while (temp != nullptr) {
        if (temp->data == value) {
            return temp; // Node found
        }
        temp = temp->next;
    }
    return nullptr; // Node not found
}

// Function to delete a node with a specific value
void deleteNode(Node*& head, int value) {
    if (head == nullptr) {
        cout << "List is empty. Nothing to delete.\n";
        return;
    }
    // Use the search function to locate the node
    Node* target = search(head, value);
    if (target == nullptr) {
        cout << "Value " << value << " not found in the list.\n";
        return;
    }

    // Handle deletion of the head node
    if (head == target) {
        Node* temp = head;
        head = head->next; // Update the head to the next node
        delete temp;
        cout << "Node with value " << value << " deleted.\n";
        traverse(head); // Call traverse to display the updated list
        return;
    }

    // Use search again to find the node's predecessor
    Node* predecessor = head;
    while (predecessor->next != target) {
        predecessor = predecessor->next;
    }

    // Perform the deletion
    predecessor->next = target->next;
    delete target;
    cout << "Node with value " << value << " deleted.\n";

    // Call traverse to display the updated list
    traverse(head);
}

int main() {
    Node* head = nullptr; // Initialize an empty list

    // Insert nodes into the list
    insert(head, 10);
    insert(head, 20);
    insert(head, 30);
    cout << "Linked List after insertion:\n";
    traverse(head);

    // Search for a node
    int searchValue = 20;
    Node* result = search(head, searchValue);
    if (result) {
        cout << "Node with value " << searchValue << " found.\n";
    } else {
        cout << "Node with value " << searchValue << " not found.\n";
    }

    // Delete a node
    deleteNode(head, 20);
    // Attempt to delete a non-existent node
    deleteNode(head, 40);

    return 0;
}