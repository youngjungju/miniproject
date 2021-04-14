#include <stdio.h>
#include "manager.h"

int main(void){
#ifdef DEBUG
        printf("Debug: %s %s %s %d\n", __DATE__, __TIME__, __FILE__, __LINE__);
#endif

    Product plist[100];
    int index = 0;
    int count = 0;
    int snum; // selected number in Menu

    count = loadData(plist);
    index = count;

    while(1){
        snum = selectMenu();
        if(snum == 0) break;
        if(snum == 1 || snum ==3 || snum == 4)
            if(count == 0) continue;
        if(snum == 1) {listProduct(plist,count);}
        else if(snum == 2){
            count += addProduct(&plist[index++]);
        }
        else if(snum == 3){
            int no = selectDataNo(plist, index);
            if(no == 0){
                printf("취소됨!\n");
                continue;
            }
            int isupd = updateProduct(&plist[no-1]);
            if(isupd == 1) printf("=> 수정성공!\n");
        }
        else if(snum == 4){
            int no = selectDataNo(plist, count);
            if (no == 0){
                printf("=> 취소됨!\n");
                continue;
            }
            int deleteok;
            printf("정말로 삭제하시겠습니까?(삭제 :1) ");
            scanf("%d",&deleteok);
            if(deleteok == 1){
                if(deleteProduct(&plist[no-1])) {
                    printf("=> 삭제됨!\n");
                }
            }
        }
        else if (snum == 5){saveData(plist,count);}
        else if (snum == 6){searchName(plist,count);}
        else if (snum == 7){searchPrice(plist,count);}
        else if (snum == 8){searchWeight(plist,count);}
    }
    printf("종료됨!\n");

    return 0;
}

