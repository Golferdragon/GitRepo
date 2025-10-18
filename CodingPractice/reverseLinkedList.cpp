// C++ Coding Practice - Implement LinkedList Reverse
// CANNOT use "using Namespace std"

// librarie(s) needed
#include <iostream>
#include <ctime>

// Node Struct
typedef struct Node {
	int data;
	struct Node* next;
} Node;

// prototype declaration
void print(const Node* curr);
void add(Node* &head, int key);
bool search(const Node* head, int key);
void remove(Node* &head, int key);
void addInOrder(Node* &head, int key);
Node* reverse_list(Node* head);
void freeList(Node* &head);

// main function
int main() {
	// LinkedList head node
	Node* test = NULL;
	Node* revTest = NULL;
	
	srand(time(0));
	
	// Initialize the LinkedList for testing
	for (int i = 0; i < 16; i++) {
		// Create a 16 element linked list, throwing rand() values for the data value
		addInOrder(test, rand() % 100);
	}		
	
	// Output linked List: element # and data value
	std::cout << "\nOriginal LinkedList:\n";
	print(test);
	
	// Input the Linked list into the reverse_list function using revTest
	revTest = reverse_list(test);
	
	// Output reversed Linked List: element # and data value
	std::cout << "\nReversed LinkedList:\n";
	print(revTest);
	
	// free up memory
	freeList(revTest);
	
	// verify list free'd
	std::cout << "\nVerification of freeing up LinkedList:\n";
	print(revTest);
	
	// Exit
	return 0;
}

// Reverse LL function
Node* reverse_list(Node* head) {
	Node *prev = NULL, *curr = head, *next = NULL;
	while (curr) {
		next = curr->next;
		curr->next = prev;
		prev = curr;
		curr = next;
	}
	return prev;
}

void remove(Node* &head, int key) {
	// if search fails, quit
	if(!search(head, key)) {
		return;
	}

	// we want to remove the head
	if(head->data == key) {
		Node* toDelete = head;
		head = head->next;
		delete toDelete;
		return;
	}

	// find the node before the one with the key
	Node* curr = head;
	while (curr->next != NULL && curr->next->data != key) {
		curr = curr->next;
	}
	if (curr->next == NULL) {
		return; // not found
	}

	// remove the node with key
	Node* toDelete = curr->next;
	curr->next = curr->next->next;
	delete toDelete;
}

bool search(const Node* head, int key) {
	while(head != NULL) {
		if(head->data == key) {
			return true;
		}
		head = head->next;
	}
	return false;
}

// function to insert value into list in correct order
void addInOrder(Node* &head, int key) {
	// storage for head pointer for modifications to pointer without modifying the actual head pointer 
	Node* curr = head;
	
	// check if list is there, if not create the start of linked list
	if(curr == NULL || curr->data > key) {
		Node* newnode = new Node;				// make newnode
		newnode->data = key;					// put data into it
		newnode->next = head;					// point newnode to head
		head = newnode;							// point the head to newnode
		return;
	}
	
	// loop through list while the next node is not NULL and the next node's data is less than key 	
	while(curr->next != NULL && curr->next->data < key) { 
		// update pointer
		curr = curr->next;
	}

	
	// create node after curr, link newnode to node after current then link current to newnode
	Node* newnode = new Node;
	newnode->data = key;
	newnode->next = curr->next;
	curr->next = newnode;
	
	// exit
	return;
}

void add(Node* &head, int key) {
	// add at the front of the list
	Node* newnode = new Node; // make a new node
	newnode->data = key;      // put data in it
	newnode->next = head;     // point it at the first node
	head = newnode;           // point the head at it
}

void print(const Node* curr) {
    int index = 0;
    while (curr != NULL) {
        std::cout << "Node " << index++ << ": \t" << curr->data << "\n";
        curr = curr->next;
    }
    std::cout << std::endl;
}

void freeList(Node* &head) {
	while (head != NULL) {
		Node* temp = head;
		head = head->next;
		delete temp;
	}
}
