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

// Function to create a header linked list
Node* createHeaderList() {
    Node* header = new Node(); // Create the header node
    header->data = 0;          // Header node data is unused or can act as a count
    header->next = nullptr;    // Initially, the list is empty
    return header;
}

// Function to insert a node at the end of the list
void insertEnd(Node* head, int value) {
    Node* newNode = createNode(value);
    Node* temp = head; // Start from the header node
    while (temp->next != nullptr) { // Traverse to the last node
        temp = temp->next;
    }
    temp->next = newNode; // Link the new node
    cout << "Inserted " << value << " at the end of the list.\n";
}

// Function to insert a node at the beginning of the list
void insertBeg(Node* head, int value) {
    Node* newNode = createNode(value);
    newNode->next = head->next; // Link new node to the first data node
    head->next = newNode;       // Update header node's next pointer
    cout << "Inserted " << value << " at the beginning of the list.\n";
}

// Function to traverse the linked list and print its elements
void traverse(Node* head) {
    if (head->next == nullptr) { // Check if the list is empty (excluding header)
        cout << "List is empty.\n";
        return;
    }
    Node* temp = head->next; // Skip the header node
    while (temp != nullptr) {
        cout << temp->data << " -> ";
        temp = temp->next;
    }
    cout << "NULL\n";
}

// Function to search for a node with a specific value
Node* search(Node* head, int value) {
    Node* temp = head->next; // Skip the header node
    while (temp != nullptr) {
        if (temp->data == value) {
            return temp; // Node found
        }
        temp = temp->next;
    }
    return nullptr; // Node not found
}

// Function to delete a node with a specific value
void deleteNode(Node* head, int value) {
    if (head->next == nullptr) { // Check if the list is empty (ignoring header)
        cout << "List is empty. Nothing to delete.\n";
        return;
    }

    // Use `search()` to find the target node
    Node* target = search(head, value);
    if (target == nullptr) {
        cout << "Value " << value << " not found in the list.\n";
        return;
    }

    // Locate the predecessor node
    Node* predecessor = head; // Start from the header node
    while (predecessor->next != target) {
        predecessor = predecessor->next;
    }

    // Delete the target node
    predecessor->next = target->next; // Bypass the target node
    delete target;                    // Free memory
    cout << "Node with value " << value << " deleted.\n";

    // Display the updated list
    traverse(head);
}

// Main function
int main() {
    // Create the header linked list
    Node* head = createHeaderList();

    // Insert nodes at the end of the list
    insertEnd(head, 10);
    insertEnd(head, 20);
    insertEnd(head, 30);

    cout << "\nLinked List after insertion at the end:\n";
    traverse(head);

    // Insert nodes at the beginning of the list
    insertBeg(head, 5);
    insertBeg(head, 2);

    cout << "\nLinked List after insertion at the beginning:\n";
    traverse(head);

    // Search for a node
    int searchValue = 20;
    Node* result = search(head, searchValue);
    if (result) {
        cout << "\nNode with value " << searchValue << " found.\n";
    } else {
        cout << "\nNode with value " << searchValue << " not found.\n";
    }

    // Delete a node
    cout << "\nDeleting node with value 20...\n";
    deleteNode(head, 20);

    // Display the updated list
    cout << "\nLinked List after deletion:\n";
    traverse(head);

    // Attempt to delete a non-existent node
    cout << "\nAttempting to delete node with value 40...\n";
    deleteNode(head, 40);

    return 0;
}