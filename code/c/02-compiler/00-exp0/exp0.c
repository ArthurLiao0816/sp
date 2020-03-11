#include <stdio.h>
#include <assert.h>
#include <string.h>
#include <ctype.h>

int tokenIdx = 0;
char *tokens;

int E();
int F();

void error(char *msg) {
  printf("%s", msg);
  assert(0);
}

//存取當前讀取的字元
char ch() {
  char c = tokens[tokenIdx];
  return c;
}

//取得目前字元，並進到下一個
char next() {
  char c = ch();
  tokenIdx++;
  return c;
}

//isNext('+-')用來判斷是否為+or-
int isNext(char *set) {
  char c = ch();
  return (c!='\0' && strchr(set, c)!=NULL);
}

//產生下一個臨時變數的代號.ex:t0.t1.t2...
int nextTemp() {
  static int tempIdx = 0; //只有第一次執行時會跑
  return tempIdx++;
}

// F =  Number | '(' E ')'
int F() {
  int f;
  char c = ch();
  if (isdigit(c)) {
    next(); // skip c
    f = nextTemp();
    printf("t%d=%c\n", f, c);
  } else if (c=='(') { // '(' E ')'
    next();
    f = E();
    assert(ch()==')');
    next();
  } else {
    error("F = (E) | Number fail!");
  }
  return f; 
}

// E = F ([+-] F)*
int E() {
  int i1 = F(); //t0=3
  while (isNext("+-")) {
    char op=next();
    int i2 = F(); //t1=5
    int i = nextTemp();
    printf("t%d=t%d%ct%d\n", i, i1, op, i2);
    i1 = i;
  }
  return i1;
}

void parse(char *str) {
  tokens = str;
  E();
}

int main(int argc, char * argv[]) {
  printf("argv[0]=%s argv[1]=%s\n", argv[0], argv[1]);
  printf("=== EBNF Grammar =====\n");
  printf("E=F ([+-] F)*\n");
  printf("F=Number | '(' E ')'\n");
  printf("==== parse:%s ========\n", argv[1]);
  parse(argv[1]);
}

/*以 3+5 為例
E = F([+-] F)*
int E(){
  int il = F();         //t0 = 3, i1 = 0
  while(isNext("+-")){  
    char op = next();   //op = +
    int i2 = F();       //t1 = 5, i2 = 1
    int i = nextTemp(); // i = 2
    printf("t%d=t%d%ct%d\n", i, i1, op, i2);
    i1=i;
  }
  return i1;
}
*/
