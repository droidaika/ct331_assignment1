#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include "genericLinkedList.h"

typedef struct listElementStruct {
	// changed data type to void so it can store any datatype as a void pointer
	void* data;
	size_t size;
	//added printfunction to print specific data types
	printFunction print;
	struct listElementStruct* next;
} listElement;

//Creates a new linked list element with given content of size
//Returns a pointer to the element
listElement* createEl(void* data, size_t size,printFunction print) {
	listElement* e = malloc(sizeof(listElement));
	if (e == NULL) {
		//malloc has had an error
		return NULL; //return NULL to indicate an error.
	}
	
	void* dataPointer = malloc(size);
	if (dataPointer == NULL) {
		//malloc has had an error
		free(e); //release the previously allocated memory
		return NULL; //return NULL to indicate an error.
	}
	//changed strcpy to memmove - can move anything rather than just chars 
	memmove(dataPointer, data,size);
	e->data = dataPointer;
	e->size = size;
	e->print = print;
	e->next = NULL;
	return e;
}


//Inserts a new element after the given el
//Returns the pointer to the new element
listElement* insertAfter(listElement* el, void* data, size_t size,printFunction print) {
	listElement* newEl = createEl(data, size,print);
	listElement* next = el->next;
	newEl->next = next;
	el->next = newEl;
	return newEl;
}


//Delete the element after the given el
void deleteAfter(listElement* after) {
	listElement* delete = after->next;
	listElement* newNext = delete->next;
	after->next = newNext;
	//need to free the memory because we used malloc
	free(delete->data);
	free(delete);
}

///////////////////////////////////////////////////////////////////////////////////

//Prints out each element in the list
void traverse(listElement* start) {
	listElement* current = start;
	while (current != NULL) {
		//calling generic print function that is passed in
		//when node was created
		current->print(current->data);
		current = current->next;
	}
}


int length(listElement* list)
{
	int num = 0;
	listElement* current = list;
	
	while(current != NULL){
		current = current->next;
		num++;
	}
	
	return num;
	
}


//Push a new element onto the head of a list
void push(listElement** list, void* data, size_t size,printFunction print) {
	//create the element that is passed in
	listElement* newEl = createEl(data, size,print);
	//setting new element's next pointer as the head pointer that was passed in
	newEl->next = *list;
	//now we set new element as the head of the list
	*list = newEl;
}
//Pop an element from the head of a list.
listElement* pop(listElement** list) {
	//creating node to store head of the list
	listElement* head = *list;
	//creating node to store popped element which is the head of the list
	listElement* poppedElement = createEl(head->data, head->size,head->print);
	//setting a newhead element as the node next to head.
	listElement* newHead = head->next;
	*list = newHead;

	//freeing the data inside head which is now not pointing to anything.
	free(head->data);
	free(head);
	return poppedElement;
}
//same as push
void enqueue(listElement** list, void* data, size_t size,printFunction print) {
	listElement* newEl = createEl(data, size,print);
	newEl->next = *list;
	*list = newEl;
}


listElement* dequeue(listElement* list) {
	//store head of list in current
	listElement* current = list;
	//store dequeued element
	listElement* deq;
	//find the last element and free that data inside it
	while (current != NULL) {
		//if last element == null - at the tail
		if (current->next->next == NULL) {
			//set deq as the last element
			deq = createEl(current->next->data, current->next->size,current->next->print);
			free(current->next->data);
			free(current->next);
			//set 2nd last element pointing to NULL
			current->next = NULL;
		}
		current = current->next;
	}
	return deq;
}






