#include <stdio.h>
#include <string.h>
#include <stdlib.h>

typedef struct{
    char name[100]; // 제품 이름
    char exp[10000];    // 제품 설명
    char weight[100];   // 제품 중량
    int price;  // 제품 가격
    int deliv;  // 제품 배송방법
} Product;

int createProduct(Product *p);  // 제품 추가
void readProduct(Product p); // 하나의 제품 출력
int updateProduct(Product *p);  // 제품 내용 수정
int deleteProduct(Product *p);  // 제품 삭제
void searchProduct(Product *p[], int count); // 제품 이름 검색
void saveData(Product *p[], int count);   // FILE 저장
int loadData(Product *p[]); // FILE 불러오기
int selectMenu(); // select num 함수

