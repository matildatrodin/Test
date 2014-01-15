#include <stdio.h>
void use_int(void *);
void use_float(void *);
void greeting(void (*)(void *), void *);

int main(void) {
  char ans;
  int i_age = 20;
  float f_age = 20.5;
  void *p;
  printf("Use int (i) or float (f)? ");
  scanf("%c", &ans);
  if (ans == 'i') {
    p = &i_age;
    greeting(use_int, p);
  }
  else {
    p = &f_age;
    greeting(use_float, p);
  }
  return 0;
}
void greeting(void (*fp)(void *), void *q) {
  fp(q);
}
void use_int(void *r) {
  int a;
  a = * (int *) r;
  printf("As an integer, you are %d years old.\n", a);
}
void use_float(void *s) {
  float *b;
  b = (float *) s;
  printf("As a float, you are %f years old.\n", *b);
}