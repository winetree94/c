#include <stdio.h>

typedef struct
{
  int num;
  char name[100];
  int cost;
} ProductInfo;

// 구조체를 인자로 받으면 값이 복사되기 때문에
// 포인터로 인자로 넘겨서 변경하는 것이 효율적임
void swapProduct(
    ProductInfo *aProduct,
    ProductInfo *bProduct)
{
  ProductInfo tmp = *aProduct;
  *aProduct = *bProduct;
  *bProduct = tmp;
}

int main()
{
  ProductInfo myProduct = {
    num : 4797283,
    name : "제주 한라봉",
    cost : 19900,
  };

  ProductInfo yourProduct = {
    num : 3959838,
    name : "전주 수박",
    cost : 430000
  };

  swapProduct(
      &myProduct,
      &yourProduct);

  ProductInfo *ptr_product = &myProduct;

  printf("상품 번호: %d \n", (*ptr_product).num);
  printf("상품 이름: %s \n", (*ptr_product).name);
  printf("상품 가격: %d \n", (*ptr_product).cost);

  // (*변수명). 과정을 -> 로 간단히 표현할 수 있음
  printf("상품 번호: %d \n", ptr_product->num);
  printf("상품 이름: %s \n", ptr_product->name);
  printf("상품 가격: %d \n", ptr_product->cost);

  return 0;
}