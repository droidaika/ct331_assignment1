#include <stdio.h>
#include "tests.h"
#include "linkedList.h"

void runTests(){
  
  listElement* l = createEl("A", 30);
  traverse(l);
  
  

  //Test insert after
  listElement* l2 = insertAfter(l, "B", 30);
  insertAfter(l2, "C", 30);
  traverse(l);
  printf("\n");

  //length test
  printf("\n Length test :");
  printf("Length = %d\n", length(l));
  printf("\n");

 //push test
  printf("Push test: \n");
  printf("Before push : ");
  printf("\n");
  traverse(l);
  printf("\n");
  push(&l, "D", 30);
  printf("Pushed: ");
  printf("\n");
  traverse(l);
  printf("\n");

  //pop test
  printf("Pop test: \n");
  printf("Before pop: ");
  printf("\n");
  traverse(l);
  printf("\n");
  listElement* poppedEl = pop(&l);
  printf("Popped: ");
  printf("\n");
  traverse(l);
  printf("\n");
  printf("Popped element : \n");
  traverse(poppedEl);
  printf("\n");

  //enqueue test
  printf("Enqueue test\n");
  printf("Before enqueue: ");
  printf("\n");
  traverse(l);
  printf("\n");
  enqueue(&l, "E", 30);
  printf("After enqueue: ");
  printf("\n");
  traverse(l);
  printf("\n");

  //dequeue test
  printf("Dequeue test");
  printf("Before dequeue: ");
  printf("\n");
  traverse(l);
  printf("\n");
  listElement* deq = dequeue(l);
  printf("\n");
  printf("After dequeue: ");
  printf("\n");
  traverse(l);
  printf("\n");
  printf("Deqeued element : ");
  traverse(deq);

}
