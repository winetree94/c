#include <stdio.h>

int declararation()
{
  printf("------------------\n");
  // 배열의 사이즈와 요소를 선언
  int a[5] = {1, 2, 3, 4, 5};

  // 사이즈 생략할 수 있음
  int b[] = {1, 2, 3};

  // 이외의 요소는 0으로 채워짐
  int c[5] = {1};

  // 이렇게 선언할 수 있지만 이미 메모리에 올라간 임의의 값이 할당될 수 있어 위험함
  // int d[4];

  // 초기화할 값들을 지정해주는 것이 좋음
  int d[4] = {0};

  // 중괄호 문법은 초기화할때만 사용할 수 있음
  // d = {1, 2, 3};
  d[1] = 3;

  printf("------------------\n");
  return 0;
}

int copy()
{
  printf("------------------\n");
  int a[] = {52, 34, 2, 12, 3};
  unsigned long size = sizeof(a);
  unsigned long len = size / sizeof(a[0]);

  int b[5] = {0};

  // 이렇게 복사해야함
  for (int i = 0; i < len; i++)
  {
    b[i] = a[i];
  }

  printf("------------------\n");
  return 0;
}

int iterate1()
{
  printf("------------------\n");
  int a[5] = {123, 534, 0x43, 3652, 2341};

  int size = sizeof(a);
  printf("배열의 크기: %d \n", size);

  int len = sizeof(a) / sizeof(a[0]);
  printf("배열의 요소 개수: %d \n", len);

  printf("배열의 요소: ");
  for (int i = 0; i < len; i++)
  {
    printf("%d", a[i]);
    if (i != len - 1)
    {
      printf(", ");
    }
  }
  printf("\n");

  printf("------------------\n");
  return 0;
}

int multi_dimension() {
  int arr[3][4] = { { 1, 2, 3, 4 }, { 5, 6, 7, 8 }, { 9, 10, 11, 12 } };

  for (int row = 0; row < 3; row++) {
    printf("현재 행: %d \n", row);
    printf("현재 행의 요소들: ");
    for (int col = 0; col < 4; col++) {
      printf("%d", arr[row][col]);
      if (col != 3)  {
        printf(", ");
      }
    }
    printf("\n");
  }

    return 0;
}

int main()
{
  declararation();
  copy();
  iterate1();
  multi_dimension();
  return 0;
}