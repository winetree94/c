#include <stdio.h>

// 함수의 프로토타입, hosting 문제를 해결
void add_number(int *, int);
void swap(int *, int *);

int factorial(int n)
{
  if (n == 1)
  {
    return n;
  }
  return n * factorial(n - 1);
}

void factorial_test()
{
  int result = factorial(5);
  printf("factorial result: %d \n", result);
}

void add_number(
    int *origin,
    int append)
{
  *origin = *origin + append;
}

void add_number_test()
{
  int result = 50;
  add_number(&result, 40);
  printf("result: %d \n", result);
}

void swap(
    int *a,
    int *b)
{
  int tmp = *a;

  *a = *b;
  *b = tmp;
}

void swap_test()
{
  int x = 15;
  int y = 40;
  swap(&x, &y);
  printf("x: %d\n", x);
  printf("y: %d\n", y);
}

// 배열은 포인터이므로, 원본 address 와 같음
void calc_array(
    int arr[]) // 어짜피 배열이 아닌 첫 요소의 포인터이기 때문에 배열 크기 생략 가능
{
  printf("arr address: %p\n", arr);
}

// arr == *arr[0] 이므로, 똑같음
// 배열은 주소값을 넘기는 call by address 만 가능함
void calc_array_2(
    int *num)
{
  printf("arr address: %p\n", num);
}

void array_test()
{
  int arr[3] = {1, 2, 3};
  printf("arr address: %p\n", arr);
  calc_array(arr);
  calc_array_2(arr);
}

int main()
{
  add_number_test();
  swap_test();
  factorial_test();
  array_test();
}
