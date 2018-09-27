
#ifndef  __list__
#define	 __list__

#include <iostream>
using namespace std;

template <class T>
// node struct
struct Node {
	T data;
	struct Node<T> *next;
};


template <class T>
// list object
class List {
private: 
	Node<T> *ptr;   // pointer to the 1st node in list

public:
	List();			// default constructor set ptr to Null
	void Insert(T data_need_to_insert);  // add a new node to the end of the list
	void Delete();  // delete a node at the end
	T Get(int pos);		// get some data from the list e.g 5th item etc.
	void PrintList(); // print all data nodes in the list
};


template <class T>
// default constructor
List<T>::List() {
	ptr = NULL;
	printf("List constructor been called .... \n");
};



template <class T>
// Insert into the list
void List<T>::Insert(T data_need_to_insert) {
	Node<T> *new_node = new Node<T>;
	new_node->data = data_need_to_insert;
	new_node->next = NULL;

	Node<T> *current = ptr;

	if (current == NULL) {
		ptr = new_node;
	}
	else {
		while (current->next != NULL) {
			current = current->next;
		}
		current->next = new_node;
	}
};



template <class T>
// delete the last linked list
void List<T>::Delete() {
	Node<T> *current = ptr;
	Node<T> *previous = NULL;

	if (current == NULL) {
		printf("The current linked list is empty. \n");
		return;
	}
	else {
		while (current->next != NULL) {
			previous = current;
			current = current->next;
		}
		if (previous != NULL && current != NULL) {
			previous->next = current->next;
			delete current;
		}
	}
};



template <class T>
// Get the nth item of the linked list
T List<T>::Get(int pos) {

	int count = 0;
	Node<T> *current = ptr;

	if (current == NULL) {
		return -1;
	}
	else {
		while (current != NULL) {
			
			if ((count + 1) == pos) {
				return current->data;
			}
			current = current->next;
			count++;
		}

		if (pos > count + 1) {
			printf("The position already exceed the length of the linked list. \n");
			return -1;
		}
	}
};



template <class T>
// print the linked list
void List<T>::PrintList() {
	int count = 0;
	Node<T> *current = ptr;
	while (current != NULL) {
		count++;

		cout << "The No." << count << " element is " << current->data << "." << endl;
		current = current->next;
	}
};


#endif 
