#include <stdio.h>

unsigned int hash(char *key){
    char *p=key;
    unsigned int h=0;
    for(;*p!='\0';p++){
        h+=*p;
    }
    return h;
}

int main() {
  printf("hash()=%u\n", hash(""));
  printf("hash(h)=%u\n", hash("h"));
  printf("hash(he)=%u\n", hash("he"));
  printf("hash(hel)=%u\n", hash("hel"));
  printf("hash(hell)=%u\n", hash("hell"));
  printf("hash(hello)=%u\n", hash("hello"));
}