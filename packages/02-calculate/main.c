#include <stdio.h>

int calculate_01() {
  int a = 5;
  int b = 5;
  int c = 5;
  int d = 5;

  printf("a + b: %d \n", a + b);
  printf("a - b: %d \n", a - b);
  printf("a * b: %d \n", a * b);
  printf("a / b: %d, \n", a / b);
  printf("a %% b: %d \n", a % b);
}

int calculate_02() {
  int a;
  double b;

  a = 10;
  b = 3;

  // 자료형이 다른 두 변수를 연산할 때, 숫자의 범위가 큰 자료형으로 자동 변환
  printf("a / b: %f \n", a / b);
  printf("b / a: %f \n", b / a);

  return 0;
}

int bitwise() {
  printf("------------------\n");
  int a = 0xAF; // 1010 1111
  int b = 0xB5; // 1011 0101

  printf("AND: %x \n", a & b); // 1010 0101
  printf("OR: %x \n", a | b); // 1011 1111
  printf("XOR: %x \n", a ^ b); // 0001 1010
  printf("NOT: %x \n", ~a); // 0101 0000
  printf("SHIFT: %x \n", a << 2); //  1010111100
  printf("SHIFT: %x \n", b >> 3); //  000101101

  printf("------------------\n");
  return 0;
}

int main() {
  calculate_01();
  calculate_02();
  bitwise();
  return 0;
}