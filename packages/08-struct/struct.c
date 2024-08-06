#include <stdio.h>

// 구조체 선언
struct
{
  float x, y;
} ppos;

// typedef 와 함께 사용
typedef struct
{
  float x, y;
} Pos;

typedef struct
{
  Pos pos;
  char *name;
} Person;

void struct_test()
{
  // 다양한 초기화 방법
  Person hansol = {
    { 234, 45645 },
    "alsdkfjsadlk"
  };
  hansol.pos.x = 33;
  hansol.pos.y = 33.33;
  hansol.name = "hansol";

  Person winetree94 = {
    pos : {
        234, 234},
    name : "winetree94"
  };

  // 구조체를 할당하면 모든 내용이 '복사' 된다.
  winetree94 = hansol;
}

int main()
{
  struct_test();
  return 0;
}