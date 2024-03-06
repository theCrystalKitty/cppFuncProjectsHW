#include <iostream>
#include <string>
#include <ctime>
using namespace std;

struct Product {
    string name;
    unsigned long long expiryDate;
    int size;
};

class Fridge {
private:
    string model;
    int size;
    int sizeProducts = 0;
    int productsAmt = 0;
    Product* products = new Product[0];
public:
    Fridge(string model, int size) {
        this->model = model;
        this->size = size;
    }

    string getModel() {
        return this->model;
    }
    int getSize() {
        return this->size;
    }
    int getProductsAmt() {
        return this->productsAmt;
    }
    Product* getProducts() {
        Product* buf = new Product[this->productsAmt];

        for (int i = 0; i < this->productsAmt; i++) {
            buf[i] = Product{ this->products[i].name, this->products[i].expiryDate, this->products[i].size };
        }

        return buf;
    }

    void showProducts() {
        for (int i = 0; i < this->productsAmt; i++) {
            cout << "name: " << this->products[i].name << endl << "size: " << this->products[i].size << endl << "expiry date: " << this->products[i].expiryDate << endl << endl;
        }
    }
    
    void addProduct(Product product) {
        if (sizeProducts == this->size || sizeProducts + product.size > this->size) {
            cout << "Fridge is full!" << endl;
        }
        Product* buf = new Product[this->productsAmt + 1];

        for (int i = 0; i < this->productsAmt; i++) {
            buf[i] = this->products[i];
        }

        buf[this->productsAmt++] = product;

        this->sizeProducts += product.size;
        delete[]this->products;
        this->products = buf;
    }

    void removeProduct(string name) {
        bool flag = false;

        for (int i = 0; i < this->productsAmt; i++) {
            if (this->products[i].name == name) {
                flag = true;
                break;
            }
        }

        if (flag) {
            cout << "No product with this name!" << endl;
            return;
        }

        flag = false;

        Product* buf = new Product[this->productsAmt - 1];

        for (int i = 0, k = 0; i < this->productsAmt; i++) {
            if (!flag && this->products[i].name == name) {
                this->sizeProducts -= products[i].size;
                continue;
            }
            buf[k++] = this->products[i];
        }

        this->productsAmt--;
        delete[]this->products;
        this->products = buf;
    }

    void removeExpired() {
        int counter = 0;
        unsigned long long timeNow = time(0);

        for (int i = 0; i < this->productsAmt; i++) {
            if (this->products[i].expiryDate <= timeNow) {
                counter++;
            }
        }

        if (counter == 0) {
            return;
        }

        Product* buf = new Product[this->productsAmt - counter];

        for (int i = 0, k = 0; i < this->productsAmt; i++) {
            if (this->products[i].expiryDate <= timeNow) {
                this->sizeProducts -= products[i].size;
                continue;
            }
            buf[k++] = this->products[i];
        }

        this->productsAmt -= counter;
        delete[]this->products;
        this->products = buf;
    }

    ~Fridge() {
        delete[]this->products;
    }
};

int main()
{
    

    return 0;
}
