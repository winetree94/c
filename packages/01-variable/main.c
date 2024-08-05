#include <stdio.h>

int variable_01() {
  int a;
  a = 127;
  printf("a 의 값은 %d 진수로 %o 입니다. \n", 8, a);
  printf("a 의 값은 %d 진수로 %d 입니다. \n", 10, a);
  printf("a 의 값은 %d 진수로 %x 입니다. \n", 16, a);

  float b = 3.141592f;
  double c = 3.141592;

  printf("b: %f \n", b);
  printf("정수로 출력하면? b: %d \n", b);
  printf("c: %f \n", c);
}

int variable_02() {
  printf("--------------\n");
  float a = 3.141592f;
  double b = 3.141592;
  int c = 123;

  // 소수점 2자리까지만 출력
  printf("a: %.2f \n", a);

  // 자릿수를 맞춰서 출력
  printf("c: %5d \n", c);

  // 자릿수는 6, 소수점은 3자리까지 출력
  printf("b: %6.3f \n", b);
  printf("--------------\n");
  return 0;
}

int variable_03() {
  int a, b, c, hi;
  float d, e, f;
  double g, programming;
  long h;
  short i;
  char j, k, hello, mineral;
}

int variable_04() {
  
}

int main()
{
  variable_01();
  variable_02();
  variable_03();
  return 0;
}
