typedef struct {
    char name[40];
    int weight;
    int price;
    int star;
    int numOfStar;
} Product;

int addProduct(Product *p);
void readProduct(Product p);
void listProduct(Product* p, int count);
int selectDataNo(Product* p, int count);
int updateProduct(Product *p);
int deleteProduct(Product *p);
int selectMenu();
int loadData(Product *p);
void saveData(Product *p, int count);
void searchName(Product *p, int count);
void searchPrice(Product *p, int count);
void searchWeight(Product *p, int count);
