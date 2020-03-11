#include <stdio.h>
void F();

void E() {
  printf("E started\n");
  F();
  printf("E finished\n");
}

void F() {
  printf("F started\nF\nF finished\n");
}

int main() {
  E();
}
