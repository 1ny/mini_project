#include <stdio.h>
#include <string.h>
#include <stdlib.h>
#include "product.h"
#include "manager.h"

// 다중데이터 버전 - 포인터배열 버전

int main() {
    Product *p[100];
    int count = 0, menu;
    int index = 0;

    count = loadData(p);
    index = count;

    while (1){
        menu = selectMenu();
        if (menu == 0) break;
        else if (menu == 1){
            if(count > 0) 
                listProduct(p, index);
            else
                printf("데이터가 없습니다.\n");
        } else if (menu == 2){
            p[index] = (Product *)malloc(sizeof(Product));
            count += createProduct(p[index++]);
        } else if (menu == 3){
            int no = selectDataNo(p, index);
            if(no == 0) {
                printf("=> 취소됨!\n");
                continue;
            }
            updateProduct(p[no-1]);
        } else if (menu == 4) {
            int no = selectDataNo(p, index);
            if(no == 0) {
                printf("=> 취소됨!\n");
                continue;
            }
            int deleteok;
            printf("정말로 삭제하시겠습니까?(삭제 :1)");
            scanf("%d", &deleteok);
            if(deleteok == 1) {
                if(p[no-1]) free(p[no-1]);
                deleteProduct(p[no-1]);
                count--;
            }
        } else if(menu == 5) {
            saveData(p, index);
        } else if(menu == 6) {
            searchProduct(p, index);
	}
    }
    printf("종료됨!\n");

    return 0;
}
