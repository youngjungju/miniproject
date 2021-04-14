#include <stdio.h>
#include <string.h>
#include "product.h"


int selectMenu(){
    int snum;
    printf("\n*** 제품검색창 ***\n1. 제품조회\n2. 제품추가\n3. 제품수정\n4. 제품삭제\n");
    printf("5. 파일저장\n");
    printf("6. 이름검색\n");
    printf("7. 가격검색\n");
    printf("8. 무게검색\n");
    printf("0. 종료\n\n");
    printf("=> 원하는 메뉴는? ");
    scanf("%d",&snum);
    return snum;
}

int addProduct(Product *p){
    printf("제품명은? : ");
    scanf(" %[^\n]",p->name);
    printf("무게는? : ");
    scanf("%d",&p->weight);
    printf("가격은? : ");
    scanf("%d",&p->price);
    printf("별점은?(1~5) : ");
    scanf("%d",&p->star);
    printf("별점 갯수는? : ");
    scanf("%d",&p->numOfStar);
    return 1;
}

void readProduct(Product p){
    printf("%s %d %d %d %d\n",p.name,p.weight,p.price,p.star,p.numOfStar);
}

void listProduct(Product* p, int count){
    printf("\nNo Name Weight Price Star NumOfStar\n");
    printf("*****************\n");
    for(int i=0; i<count; i++){
        if(p[i].price == -1) continue;
        printf("%d ",i+1);
        readProduct(p[i]);
    }
    printf("\n");
}

int selectDataNo(Product* p, int count){
    int no;
    listProduct(p, count);
    printf("번호는 (취소 : 0)? ");
    scanf("%d", &no);
    return no;
}

int updateProduct(Product *p){
    printf("새 제품명은? : ");
    scanf(" %[^\n]",p->name);
    printf("새 무게는? : ");
    scanf("%d",&p->weight);
    printf("새 가격은? : ");
    scanf("%d",&p->price);
    printf("새 별점은? : ");
    scanf("%d",&p->star);
    printf("새 별점 갯수는? : ");
    scanf("%d",&p->numOfStar);
    return 1;
}

int deleteProduct(Product *p){
    p->price = -1;
    return 1;
}

int loadData(Product *p){
    FILE *fp;
    fp = fopen("product.txt","rt");
    int i = 0;

    if(fp == NULL){
        printf("=>파일 없음\n");
    }
    else {
        for(; i<100; i++){
            fscanf(fp," %[^,], %d %d %d %d",p[i].name, &p[i].weight, &p[i].price, &p[i].star, &p[i].numOfStar);
            if (feof(fp)) break;
        }
        fclose(fp);
        printf("=> 로딩 성공!\n");
    }
    return i;
}

void saveData(Product *p, int count){
    FILE *fp;
    fp = fopen("menu.txt","wt");

    for(int i=0; i<count; i++){
        if(p[i].price == -1) continue;
        fprintf(fp,"%s, %d %d %d %d\n",p[i].name,p[i].weight,p[i].price,p[i].star,p[i].numOfStar);
    }
    fclose(fp);
    printf("저장됨!\n");
}
void searchName(Product *p, int count){
    char searchn[20];
    int scnt = 0;

    printf("검색할 제품 이름? ");
    scanf(" %s",searchn);

    printf("\nNo Name Weight Price Star NumOfStar\n");
    printf("================================\n");
    for(int i = 0; i<count; i++){
        if(p[i].price == -1) continue;
        if(strstr(p[i].name, searchn)){
            printf("%2d ",i+1);
            readProduct(p[i]);
            scnt ++;
        }
    }
    if(scnt == 0) printf("=> 검색된 데이터 없음!");
    printf("\n");
}

void searchPrice(Product *p, int count){
    int searchp;
    int scnt = 0;

    printf("검색할 제품 가격? ");
    scanf("%d", &searchp);

    printf("\nNo Name Weight Price Star NumOfStar\n");
    printf("================================\n");
    for(int i = 0; i<count; i++){
        if(p[i].price == -1) continue;
        if(p[i].price == searchp){
            printf("%2d ",i+1);
            readProduct(p[i]);
            scnt ++;
        }
    }
    if(scnt == 0) printf("=> 검색된 데이터 없음!");
    printf("\n");
};
void searchWeight(Product *p, int count){
    int searchw;
    int scnt = 0;

    printf("검색할 제품 무게? ");
    scanf("%d",&searchw);

    printf("\nNo Name Weight Price Star NumOfStar\n");
    printf("================================\n");
    for(int i = 0; i<count; i++){
        if(p[i].weight == -1) continue;
        if(p[i].weight == searchw){
            printf("%2d ",i+1);
            readProduct(p[i]);
            scnt ++;
        }
    }
    if(scnt == 0) printf("=> 검색된 데이터 없음!");
    printf("\n");
};

int main(void){
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
            if(count>=1){
                printf("full !!\n");
                continue;
            }
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
