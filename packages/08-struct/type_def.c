#include <stdio.h>

// 타입 선언
typedef unsigned short int age_t;
typedef float point_t[2];
typedef char *string;

age_t userAge = 33;
point_t userAxis = {23.23, 25.32};
point_t userAxiss[] = {
    {23, 24},
    {23, 24}};

string name = "hansol";

// string 이렇게 선언할 수도 있음
char *name2 = "hansol";

int main()
{
  return 0;
}