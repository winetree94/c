#include <stdio.h>

int basic()
{
  int a = 3;
  int *b = &a;

  // 메모리 주소 출력
  printf("a: %p \n", b);

  // 메모리 주소에 있는 값 출력
  printf("a: %d \n", *b);

  return 0;
}

int reference()
{
  printf("--------------\n");

  int a;
  int b;
  int *p;

  // 참조 및 역참조로 변수의 값을 조작
  p = &a;
  *p = 2;
  p = &b;
  *p = 4;

  printf("a: %d \n", a);
  printf("b: %d \n", b);

  printf("--------------\n");
  return 0;
}

int constant_pointer_01()
{
  printf("--------------\n");

  int a;
  int b;

  // 상수 int 를 참조하는 pa 변수 선언
  // pa 변수가 상수인 것이 아님
  const int *pa = &a;

  // pa 변수 자체는 변경 가능
  pa = &b;

  // pa 변수는 상수 int 를 참조하므로, 변경 불가
  // *pa = 3;

  printf("--------------\n");
  return 0;
}

int constant_pointer_02() {
  printf("--------------\n");

  int a;
  int b;

  // int 를 참조하는 변수 pa 를 상수로 선언
  // pa 변수는 상수임
  int* const pa = &a;

  // 역참조를 통한 a는 변경 가능
  *pa = 3;
  // pa 변수 자체는 변경 불가능
  // pa = &b;

  printf("--------------\n");
  return 0;
}

int pointer_calculate() {
  printf("--------------\n");

  int a;
  int *pa = &a;

  printf("pa 의 값: %p \n", pa);

  // 포인터에서 1을 더하면 포인터 주소 + 포인터가 가리키는 자료형의 크기만큼 이동
  printf("pa + 1 의 값: %p \n", pa + 1);

  // 포인터에서 1을 빼면 포인터 주소 - 포인터가 가리키는 자료형의 크기만큼 이동
  printf("pa - 1 의 값: %p \n", pa - 1);

  printf("--------------\n");
  return 0;
}

int main()
{
  basic();
  reference();
  constant_pointer_01();
  constant_pointer_02();
  pointer_calculate();
  return 0;
}