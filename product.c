#include <stdio.h>
#include <string.h>
#include <stdlib.h>
#include "product.h"

int loadData(Product *p[]) {    // FILE에 저장된 제품 목록을 불러오는 함수; txt파일이 없을 경우 '파일 없음' 출력
    int i = 0;
    FILE *fp;

    if((fp = fopen("product.txt", "rt"))) {
        for(; i<100; i++) {
            if(feof(fp)) {
                break;
            }
            p[i] = (Product*)malloc(sizeof(Product));
            fgets(p[i]->name, 100, fp);
            p[i]->name[strlen(p[i]->name) - 1] = '\0';
            fgets(p[i]->weight, 100, fp);
            p[i]->weight[strlen(p[i]->weight) - 1] = '\0';
            fgets(p[i]->exp, 10000, fp);
            p[i]->exp[strlen(p[i]->exp) - 1] = '\0';
            fscanf(fp, "%d %d\n", &p[i]->price, &p[i]->deliv);
        }
        fclose(fp);
        printf("=> 로딩 성공!\n");


    } else {
        printf("=> 파일 없음\n\n");
    }
    return i;
}

void saveData(Product *p[], int count) {// FILE에 제품 목록을 저장하는 함수
    FILE *fp;
    fp = fopen("product.txt", "wt");

    for(int i=0; i<count; i++) {
        if(p[i]->price == -1) continue;
        fprintf(fp, "%s\n%s\n%s\n%d\n%d\n\n", p[i]->name, p[i]->weight, p[i]->exp, p[i]->price, p[i]->deliv);
    }

    fclose(fp);

    printf("=> 저장됨!\n");
}

int loadData(Product *p[]) {    // FILE에 저장된 제품 목록을 불러오는 함수; txt파일이 없을 경우 '파일 없음' 출력
    int i = 0;
    FILE *fp;

    if((fp = fopen("product.txt", "rt"))) {
        for(; i<100; i++) {
            if(feof(fp)) {
                break;
            }
            p[i] = (Product*)malloc(sizeof(Product));
            fgets(p[i]->name, 100, fp);
            p[i]->name[strlen(p[i]->name) - 1] = '\0';
            fgets(p[i]->weight, 100, fp);
            p[i]->weight[strlen(p[i]->weight) - 1] = '\0';
            fgets(p[i]->exp, 10000, fp);
            p[i]->exp[strlen(p[i]->exp) - 1] = '\0';
            fscanf(fp, "%d %d\n", &p[i]->price, &p[i]->deliv);
        }
        fclose(fp);
        printf("=> 로딩 성공!\n");

#ifdef DEBUG
    printf("\n[ 변수값 확인- DEBUG MODE ]\n");
    printf("로딩된 상품 개수: %d\n\n", i);
#endif

    } else {
        printf("=> 파일 없음\n\n");
    }
    return i;
}

int createProduct(Product *p) { // 제품을 추가하는 함수
    printf("제품 이름: ");
    getchar();
    fgets(p->name, 100, stdin);
    p->name[strlen(p->name) - 1] = '\0';
    printf("제품 설명: ");
    fgets(p->exp, 10000, stdin);
    p->exp[strlen(p->exp) - 1] = '\0';
    printf("제품 중량: ");
    scanf("%s", p->weight);
    printf("제품 가격: ");
    scanf("%d", &p->price);
    printf("제품 배송방법(1:새벽배송, 2:택배배송): ");
    scanf("%d", &p->deliv);

    printf("=>추가됨!\n");

    return 1;
}

void readProduct(Product p) {    // 제품 하나의 내용을 출력하는 함수
    printf("%s %s %s %d원 %s\n", p.name, p.weight, p.exp, p.price, (p.deliv == 1) ? "새벽배송" : "택배배송");
}

int updateProduct(Product *p) { // 제품 정보를 수정하는 함수
    printf("제품 이름: ");
    getchar();
    fgets(p->name, 100, stdin);
    p->name[strlen(p->name) - 1] = '\0';
    printf("제품 설명: ");
    fgets(p->exp, 10000, stdin);
    p->exp[strlen(p->exp) - 1] = '\0';
    printf("제품 중량: ");
    scanf("%s", p->weight);
    printf("제품 가격: ");
    scanf("%d", &p->price);
    printf("제품 배송방법(1:새벽배송, 2:택배배송): ");
    scanf("%d", &p->deliv);
    printf("=> 수정됨!\n");

    return 0;
}

int deleteProduct(Product *p) { // 제품 정보를 삭제하는 함수
    p->price = -1;
    printf("=> 삭제됨!\n");

    return 1;
}

int selectMenu() {  // 수행할 작업을 묻는 함수
    int menu;
    printf("\n*** Fruit ***\n");
    printf("1. 제품 조회\n");
    printf("2. 제품 추가\n");
    printf("3. 제품 수정\n");
    printf("4. 제품 삭제\n");
    printf("5. 제품 저장\n");
    printf("6. 제품 검색\n");
    printf("0. 종료\n\n");
    printf("=> 원하는 메뉴는? ");
    scanf("%d", &menu);
    return menu;
}
