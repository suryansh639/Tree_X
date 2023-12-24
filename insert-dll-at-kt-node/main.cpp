#include <iostream>
#include <bits/stdc++.h>

using namespace std;

// Define a Node class for doubly linked list
class Node {
public:
    // Data stored in the node
    int data;   
    // Pointer to the next node in the list (forward direction)
    Node* next;     
    // Pointer to the previous node in the list (backward direction)
    Node* back;     

    // Constructor for a Node with both data, a reference to the next node, and a reference to the previous node
    Node(int data1, Node* next1, Node* back1) {
        data = data1;
        next = next1;
        back = back1;
    }

    // Constructor for a Node with data, and no references to the next and previous nodes (end of the list)
    Node(int data1) {
        data = data1;
        next = nullptr;
        back = nullptr;
    }
};

// Function to convert an array to a doubly linked list
Node* convertArr2DLL(vector<int> arr) {
    // Create the head node with the first element of the array
    Node* head = new Node(arr[0]);
    // Initialize 'prev' to the head node
    Node* prev = head;            

    for (int i = 1; i < arr.size(); i++) {
        // Create a new node with data from the array and set its 'back' pointer to the previous node
        Node* temp = new Node(arr[i], nullptr, prev);
        // Update the 'next' pointer of the previous node to point to the new node
        prev->next = temp; 
         // Move 'prev' to the newly created node for the next iteration
        prev = temp;       
    }
    // Return the head of the doubly linked list
    return head;  
}

// Function to print the elements of the doubly linked list
void print(Node* head) {
    while (head != nullptr) {
        // Print the data in the current node
        cout << head->data << " ";  
         // Move to the next node
        head = head->next;         
    }
}

// This function was explain in prevoius articles 
// Please refer there
// Function to insert new node before head
Node* insertBeforeHead(Node* head, int val){
    // Create new node with data as val
    Node* newHead = new Node(val , head, nullptr);
    head->back = newHead;
    
    return newHead;
}


// This function was explain in prevoius articles 
// Please refer there
Node* insertBeforeTail(Node* head, int val){
    // Edge case, if dll has only one elements
    if(head->next==NULL){
        // If only one element
        return insertBeforeHead(head, val);
    }
    
    // Create pointer tail to traverse to the end of list
    Node* tail = head;
    while(tail->next!=NULL){
        tail = tail->next;
    }
    // Keep track of node before tail using prev
    Node* prev = tail->back;
    
    // Create new node with value val
    Node* newNode = new Node(val, tail, prev);
    
    // Join the new node into the doubly linked list
    prev->next = newNode;
    tail->back = newNode;
    
    // Return the updated linked list
    return head;
}


// Function to insert before the Kth element 
Node* insertBeforeKthElement(Node* head, int k, int val){
    
    if(k==1){
        // K = 1 means node has to be insert before the head
        return insertBeforeHead(head, val);
    }
    
    // temp will keep track of the node
    Node* temp = head;
    
    // count so that the Kth element can be reached
    int count = 0;
    while(temp!=NULL){
        count ++;
        // On reaching the Kth position, break out of the loop
        if(count == k) break;
        // keep moving temp forward till count != K
        temp = temp->next;
    }
    // track the node before the Kth node
    Node* prev = temp->back;
    
    // create new node with data as val
    Node* newNode = new Node(val, temp, prev);
    
    //join the new node in between prev and temp
    prev->next = newNode;
    temp->back = newNode;
    
    // Set newNode's pointers to prev and temp
    newNode->next = temp;
    newNode->back = prev;
    
    // Return the head of the updated doubly linked list
    return head;
}


int main() {
    vector<int> arr = {12, 5, 8, 7, 4};
    Node* head = convertArr2DLL(arr);
    
    print(head);
    cout << endl << "Doubly Linked List After Inserting val on the kth position: " << endl;
    head = insertBeforeKthElement(head, 2, 10);
    print(head);

    return 0;
}