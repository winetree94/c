#include <stdio.h>
#include <string.h>

int basic()
{
  printf("basic----------------\n");
  int num = 3;

  // pointer 변수 선언
  int *pnum;

  // pnum pointer 에 num 의 포인터 할당
  pnum = &num;

  printf("num 의 값: %d \n", num);
  printf("num 의 메모리 주소값: %p \n", &num);
  printf("pnum 의 메모리 주소값: %p \n", pnum);
  printf("pnum 의 참조 값: %d \n", *pnum);

  // pointer 의 역참조 수정, 실제 num 을 수정한 것
  *pnum = 5;
  printf("num 의 값: %d \n", num);
  printf("pnum 의 참조 값: %d \n", *pnum);
  printf("----------------\n");
}

int basic2()
{
  printf("basic2----------------\n");

  int a = 10;
  int b = 20;

  int *ptr = &a;
  printf("ptr 이 가리키는 변수의 값: %d \n", *ptr);

  ptr = &b;
  printf("ptr 이 가리키는 변수의 값: %d \n", *ptr);

  // null pointer, 가리키는 대상이 없음
  ptr = NULL;
  // null pointer 를 역참조하면 오류
  // int c = *ptr;

  printf("----------------\n");
}

int double_pointer()
{
  printf("double pointer----------------\n");

  int a = 10;
  int *ptr_a = &a;

  // 포인터의 포인터를 만들 수 있음
  int **ptr_ptr_a = &ptr_a;

  printf("1. a = %d \n", a);
  // &와 ptr_a 는 같음 (같은 주소값)
  printf("2. &a = %p \n", &a);
  printf("3. ptr_a = %p \n", ptr_a);
  // &ptr_a 와 ptr_ptr_a 는 같음 (같은 주소값)
  printf("4. &ptr_a = %p \n", &ptr_a);
  printf("5. ptr_ptr_a %p \n", ptr_ptr_a);
  // &ptr_ptr_a 는 별도의 주소값
  printf("6. &ptr_ptr_a %p \n", &ptr_ptr_a);

  // ptr_ptr_a 를 역참조하면, *ptr_a 가 나옴
  printf("7. *ptr_ptr_a %p \n", *ptr_ptr_a);
  // ptr_ptr_a 를 2회 역참조하면 a의 값이 나옴
  printf("8. **ptr_ptr_a %d \n", **ptr_ptr_a);

  printf("----------------\n");
}

int array_and_pointer()
{
  printf("array and pointer----------------\n");

  int a = 10;

  printf("&a = %p \n", &a);
  // 포인터에 +- 1을 하면 데이터 사이즈(int 의 경우 4byte)만큼 추가된다.
  printf("&a - 1 = %p \n", &a - 1);
  printf("&a + 1 = %p \n", &a + 1);

  // 포인터의 연산 특성을 활용하면 배열 요소의 포인터 주소를 알 수 있다.
  int arr[10] = {1, 2, 3, 4, 5, 6, 7, 8, 9, 10};
  // 배열의 이름은 첫번째 요소의 포인터를 가리킨다.
  printf("arr 의 주소: %p \n", arr);
  for (int i = 0; i < 10; i++)
  {
    printf("arr[%d]의 주소: %p \n", i, &arr[i]);
    // 배열의 이름 특성을 활용해서 아래와 같이 작성할 수도 있다.
    // printf("arr[%d]의 주소: %p \n", i, arr + i);
    printf("arr[%d]의 값: %d \n", i, arr[i]);
    // 배열의 특성을 활용해서 포인터 역참조로 값에 접근할 수 있다.
    // printf("arr[%d]의 값: %d \n", i, *(arr + i));
  }

  // 배열의 이름이 첫번째 요소를 가리키는 포인터인 덕분에
  // 포인터를 통해서도 배열에 접근할 수 있다.
  int *ptr = arr;
  for (int i = 0; i < 10; i++)
  {
    // printf("ptr[%d]의 주소: %p \n", i, ptr + i);
    printf("ptr[%d]의 주소: %p \n", i, &ptr[i]);
    // printf("ptr[%d]의 값: %d", i, ptr[i]);
    printf("ptr[%d]의 값: %d \n", i, *(ptr + i));
  }

  // pointer 를 통해서도 루프를 돌릴 수 있음
  for (int *ptr = arr; ptr < arr + 10; ptr++)
  {
    printf("arr[%ld]의 값: %d \n", arr - ptr, *ptr);
  }

  printf("----------------\n");
}

int pointer_of_array_01()
{
  printf("pointer_of_array_01----------------\n");
  int arr[10];

  // 모두 동일한 첫번째 요소의 포인터가 반환됨
  printf("&arr: %p \n", &arr);
  printf("arr: %p \n", arr);
  printf("&arr[0]: %p \n", &arr[0]);

  // 배열 포인터의 선언
  int(*p_arr)[];
  p_arr = &arr;

  // 배열 포인터에 배열을 넣을 순 없다.
  // p_arr = arr;

  // 이제 진짜 배열의 포인터가 반환됨
  printf("&p_arr: %p \n", &p_arr);

  // 배열 포인터의 역참조를 통해 요소에 접근할 수 있음
  printf("(*p_arr)[0]: %d \n", (*p_arr)[0]);

  printf("----------------\n");
}

int pointer_of_array_02()
{
  printf("pointer_of_array_02----------------\n");

  int arr[3][4] = {{1, 2, 3, 4}, {5, 6, 7, 8}, {9, 10, 11, 12}};

  // 배열의 포인터 선언
  // 이렇게 포인터 참조를 만들 수 있음
  int(*ptr)[4] = arr;

  printf("&arr[0]: %p\n", &arr[0]);
  printf("arr: %p\n", arr);
  printf("ptr: %p\n", ptr);
  printf("&ptr: %p\n", &ptr); // 배열 포인터의 메모리 주소

  printf("&arr[1]: %p\n", &arr[1]);
  printf("arr + 1: %p\n", arr + 1);
  printf("&arr[0] + 1: %p\n", &arr[0] + 1);

  // 배열 포인터로 하위 배열을 꺼낼 수 있음
  int(*row_0)[] = &arr[0];
  int(*row_1)[] = &arr[1];

  // 2차 배열에서의 포인터 활용
  for (int(*pi)[4] = arr; pi < arr + 3; pi++)
  {
    printf("행: %p \n", *pi);

    printf("열: ");
    for (int *pj = *pi; pj < *pi + 4; pj++)
    {
      printf("%4d", *pj);
    }

    printf("\n");
  }

  printf("----------------\n");
}

int pointers_array_01()
{
  printf("pointers_array_01----------------\n");
  // 포인터 배열 선언
  int *ptr[3];
  int a = 3;
  // 포인터 배열에 포인터 할당
  ptr[0] = &a;

  printf("*ptr[0] %d\n", *ptr[0]);
  printf("----------------\n");
}

int pointers_array_02()
{
  printf("pointers_array_02----------------\n");
  char str[4][10] = {"hello", "world", "doodle", "google"};

  char *ptr[4];

  for (int i = 0; i < 4; i++)
  {
    ptr[i] = str[i];
    printf("str[%d]: %s \n", i, str[i]);
  }

  for (char(*word)[10] = str; word < str + 4; word++)
  {
    printf("word: %s \n", *word);
  }

  printf("----------------\n");
}

int main()
{
  basic();
  basic2();
  double_pointer();
  array_and_pointer();
  pointer_of_array_01();
  pointer_of_array_02();
  pointers_array_01();
  pointers_array_02();
  return 0;
}