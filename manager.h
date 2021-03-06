//manager.h
//구조체
typedef struct {
    char name[40];
    int weight;
    int price;
    int star;
    int numOfStar;
} Product;
//상품 추가함수 
int addProduct(Product *p);
//읽기 함수 
void readProduct(Product p);
void listProduct(Product* p, int count);
//상품 넘버 선택 
int selectDataNo(Product* p, int count);
//상품 업데이트
int updateProduct(Product *p);
//상품 삭제
int deleteProduct(Product *p);
//메뉴 리스트 출력	
int selectMenu();
//데이터로드
int loadData(Product *p);
void saveData(Product *p, int count);
//상품 이름 검색
void searchName(Product *p, int count);
//상품 가격 검색 
void searchPrice(Product *p, int count);
//상품 무게 검색
void searchWeight(Product *p, int count);




