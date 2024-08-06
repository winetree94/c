#include <stdio.h>
#include <string.h>

int basic()
{
  // 이렇게 문자열(string)을 선언
  // 모든 문자열에는 끝에 null 문자가 들어가야 해서 배열의 길이를 +1 로 잡아야 함
  char name[6] = "hello";
  // 이렇게 선언된 것과 같음
  // char name[6] = {'h', 'e', 'l', 'l', 'o', '\0' };

  unsigned long size = sizeof(name);

  printf("name1 값: %s \n", name);
  printf("배열 바이트 사이즈: %ld \n", size);

  // 일반 배열처럼 다룰 수 있다.
  name[2] = 'c';

  // 길이를 임의로 늘려 놓을 수 있다.
  char name2[100] = "hello \0, world!";

  // %s 는 null 문자까지만 출력한다.
  printf("name2 값: %s \n", name2);

  // 선언 후 단순 대입은 할 수 없음
  // name2 = "change";

  return 0;
}

int scan()
{
  printf("------------------\n");
  printf("이름을 입력하세요.");
  // 미리 지정한 사이즈만큼만 입력할 수 있다.
  char name[100];
  // 단어 단위로 받는 기능이므로 공백 이후의 문자열은 생략된다.
  scanf("%s", name);
  printf("입력한 이름은 \"%s\" 입니다.", name);
  printf("------------------\n");
}

// strlen 은 1바이트당 1로 측정함
// 한글 등 utf-8 이 필요한 인코딩에선 문자형당 가변 바이트를 가지기 때문에
// 별도의 측정 로직이 필요함
// 
// 0xxxxxxx: 1바이트 문자 (ASCII)
// 110xxxxx: 2바이트 문자 시작
// 1110xxxx: 3바이트 문자 시작
// 11110xxx: 4바이트 문자 시작
// 10xxxxxx: 연속 바이트
unsigned long utf8_strlen(const char *s) {
    unsigned long length = 0;
    while (*s) {
        if ((*s & 0xC0) != 0x80) { // 0x80 (10xxxxxx) is a continuation byte
            length++;
        }
        s++;
    }
    return length;
}

int helper_functions()
{
  printf("----------helper_functions--------\n");
  char name[100] = "박한솔";

  // 문자열의 길이를 측정
  int len = strlen(name);

  printf("문자열: %s \n", name);
  printf("ascii 문자열의 길이 %ld \n", strlen(name));
  printf("utf-8 문자열의 길이 %ld \n", utf8_strlen(name));

  char name2[100];

  // 문자열의 복사, 대상의 기존 문자열을 대체한다.
  strcpy(name2, name);
  strcpy(name2, "hello!");
  printf("복사한 문자열: %s \n", name2);

  // 문자열의 합성
  strcat(name2, name);
  strcat(name2, ", added");
  printf("추가된 문자열: %s \n", name2);

  // overflow 를 막기 위한 좀 더 안전한 방법
  // 3번재 인자의 크기만큼만 처리한다.
  strncpy(name2, name, sizeof(name2));

  // 추가 가능한 크기: 총크기 - 기존크기 - 1(null 문자 공간)
  // strncat 은 항상 null 문자를 집어넣음
  strncat(name2, name, sizeof(name2) - strlen(name2) - 1);

  printf("------------------\n");
}

int compare() {
  printf("compare------------------\n");
  char str1[] = "simple";
  char str2[] = "sample";

  if (strcmp(str1, str2) < 0) {
    printf("%s 는 %s 보다 사전순으로 빠릅니다. \n", str1, str2);
  } else if (strcmp(str1, str2) == 0) {
    printf("%s 와 %s 는 같습니다. \n", str1, str2);
  } else if (strcmp(str1, str2) > 0) {
    printf("%s 는 %s 보다 사전순으로 늦습니다. \n", str1, str2);
  }
  printf("------------------\n");
}

int main()
{
  basic();
  // scan();
  helper_functions();
  compare();
  return 0;
}
