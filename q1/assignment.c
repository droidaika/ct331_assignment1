#include <stdio.h>

int main(int arg, char* argc[]){
  printf("Hello assignment1.\n");

  int integer;
  int* intPoint;
  long Long;
  double* dubPoint;
  char** dubCharPoint;

  printf("Integer size is %d \n", sizeof(integer));
  printf("Integer pointer size is %d \n", sizeof(intPoint));
  printf("Long size is %d \n", sizeof(Long));
  printf("Double pointer size is %d \n", sizeof(dubPoint));
  printf("Double character pointer is %d \n", sizeof(dubCharPoint));
  
  return 0;
}
