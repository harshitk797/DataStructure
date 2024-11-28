/*
Step 1 - You have to create a circular linked list which store the names of the students who want to be participate in election.

Step 2 - Take any positive value [i] from user (1 to n-1) where n is the number of nodes.

Step 3 - Start counting from any one node of the circular linked list.

step 4 - Remove every ith node from the list and start counting from next node

Step 5 - Repeat 3 and 4 till until the last element remains.

Step 6 - Display the value of the last node. 
*/
#include <iostream>
#include <string>
using namespace std;

// Node structure for the circular linked list
struct Node {
    string name;  // Store the name of the participant
    Node* next;   // Pointer to the next node
};

int main() {
    Node* H= NULL;  // Pointer to the head of the list
    Node* T= NULL;  // Pointer to the tail of the list

    int Count = 0;  // For tracking the number of nodes

    // Adding participants to the list
    string name;
    char choice;
    do {
        cout << "Enter participant's name: ";
        cin >> name;

        // Create a new node
        Node* newNode = new Node();
        newNode->name = name;
        newNode->next = NULL;

        if (H==NULL) {
            // If the list is empty, initialize head and tail
            H = newNode;
            T = newNode;
            newNode->next = H;  // Circular connection
        } else {
            // Add the new node at the end and update the circular linked list
            T->next = newNode;
            newNode->next = H;
            T = newNode;
        }

        Count++;  // Increment the node count
        cout << "Do you want to add another participant? (y/n): ";
        cin >> choice;
    } while (choice == 'y' || choice == 'Y');

    // Display the list of participants
    cout << "Initial List of Participants:" << endl;
    if (H==NULL) {
        cout << "No participants." << endl;
    } else {
        Node* temp = H;
        do {
            cout << temp->name << " -> ";
            temp = temp->next;
        } while (temp != H);
        cout << "(back to " << H->name << ")" << endl;
    }

    // Get the step value for elimination
    int step;
    cout << "Enter the step value (1 to " << Count - 1 << "): ";  
    cin >> step;

    // Finding the last remaining participant
    Node* curr = H;
    Node* prev = NULL;

    while (curr->next != curr) {
        for (int i=1; i<=step; i++) {
            prev = curr;
            curr = curr->next;
        }
        cout << "Eliminating: " << curr->name << endl;
        prev->next = curr->next;

        if (curr == H) {
            H = curr->next;  
        }
        delete curr;
        curr = prev->next;  
    }

    // Display the last remaining participant
    cout << "The last remaining participant is: " << curr->name << endl;
    delete curr;  // Clean up the last node
    H = NULL;

    return 0;
}
