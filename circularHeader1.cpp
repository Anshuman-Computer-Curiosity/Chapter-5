#include <iostream>
using namespace std;

// Define the structure of a node
struct Node {
    int data;       // Data part of the node
    Node* next;     // Pointer to the next node
};

// Function to create the header node
Node* createHeader() {
    Node* header = new Node();
    header->data = -1;   // Header node has no meaningful data
    header->next = header; // Points to itself
    return header;
}

// Function to create a new node
Node* createNode(int value) {
    Node* newNode = new Node();
    newNode->data = value;
    newNode->next = nullptr;
    return newNode;
}

//function to insert at begin
void insertAtBeginning(Node* header, int value) {
    Node* newNode = createNode(value);
    newNode->next = header->next;
    header->next = newNode;
}

// Function to insert a node at the end
void insertEnd(Node* header, int value) {
    Node* newNode = createNode(value);
    Node* temp = header; // Start from the header node
    while (temp->next != header) { // Traverse to the last node
        temp = temp->next;
    }
    temp->next = newNode; // Link the new node at the end
    newNode->next = header; // Maintain circular structure
    cout << "Inserted value " << value << " into the list.\n";
}

// Function to traverse the circular header linked list
void traverse(Node* header) {
    if (header->next == header) {
        cout << "List is empty.\n";
        return;
    }
    Node* temp = header->next; // Start from the first data node
    cout << "List contents: ";
    while (temp != header) {
        cout << temp->data << " -> ";
        temp = temp->next;
    }
    cout << "HEADER\n";
}

// Function to search for a node in the list
Node* search(Node* header, int value) {
    Node* temp = header->next; // Start from the first data node
    while (temp != header) {
        if (temp->data == value) {
            return temp; // Node found
        }
        temp = temp->next;
    }
    return nullptr; // Node not found
}

// Function to delete a node with a specific value
void deleteNode(Node* header, int value) {
    if (header->next == header) {
        cout << "List is empty. Nothing to delete.\n";
        return;
    }

    // Use the search function to check if the node exists
    Node* target = search(header, value);
    if (target == nullptr) {
        cout << "Value " << value << " not found in the list.\n";
        return;
    }

    // Find the predecessor of the target node
    Node* prev = header;
    while (prev->next != target) {
        prev = prev->next;
    }

    // Perform deletion
    prev->next = target->next; // Bypass the target node
    delete target;             // Free memory
    cout << "Node with value " << value << " deleted.\n";
}

// Main function to test the circular header linked list
int main() {
    // Create the header node
    Node* header = createHeader();

    // Insert nodes into the list
    insertEnd(header, 10);
    insertEnd(header, 20);
    insertAtBeginning(header, 5);

    // Display the list
    cout << "Linked list after insertion:\n";
    traverse(header);

    // Search for a node
    int searchValue = 20;
    Node* result = search(header, searchValue);
    if (result) {
        cout << "Node with value " << searchValue << " found.\n";
    } else {
        cout << "Node with value " << searchValue << " not found.\n";
    }

    // Delete a node
    deleteNode(header, 20);
    cout << "Linked list after deletion:\n";
    traverse(header);

    // Attempt to delete a non-existent node
    deleteNode(header, 40);

    // Delete the remaining nodes
    deleteNode(header, 10);
    deleteNode(header, 5);

    // Display the list after all deletions
    cout << "Linked list after all deletions:\n";
    traverse(header);

    return 0;
}