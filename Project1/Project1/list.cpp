/*
#include <stdio.h>
#include "list.h"


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
		while (current->next != NULL) {
			current = current->next;
			count++;
			if ((count + 1) == pos) {
				return current->data;
			}
			else {
				continue;
			}
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

		printf("The No.%d element is %d.\n", count, current->data);
		current = current->next;
	}
};


*/