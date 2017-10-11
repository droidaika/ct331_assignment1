#ifndef CT331_ASSIGNMENT_LINKED_LIST
#define CT331_ASSIGNMENT_LINKED_LIST

typedef struct listElementStruct listElement;


typedef void(*printFunction)(void* data);


listElement* createEl(void* data, size_t size, printFunction print);

void traverse(listElement* start);


listElement* insertAfter(listElement* after, void* data, size_t size, printFunction print);

void deleteAfter(listElement* after);

int length(listElement* list);

void push(listElement** list, void* data, size_t size,printFunction print);

listElement* pop(listElement** list);

void enqueue(listElement** list, void* data, size_t size, printFunction print);

listElement* dequeue(listElement* list);

#endif