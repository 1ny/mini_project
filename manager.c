#include <stdio.h>
#include <stdlib.h>
#include "product.h"
#include "manager.h"

void listProduct(Product *p[], int count) {
    printf("===================================\n");
    for(int i=0; i<count; i++) {
        if(p[i] == NULL) continue;
        printf("%2d ", i+1);
        readProduct(*p[i]);
    }
    printf("\n");
}

int selectDataNo(Product *p[], int count) { // 수정/삭제할 때 몇번 제품을 수정/삭제할 지 묻는 함수
    int no;
    listProduct(p, count);
    printf("번호는 (취소 :0)? ");
    scanf("%d", &no);
    return no;
}
