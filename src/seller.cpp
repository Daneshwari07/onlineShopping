#include "seller.h"

Seller::Seller(string n, string e, string p, string a, int sid, string st, float r)
    : User(n, e, p, a), sellerid(sid), store(st), rating(r) {}

void Seller::login() { cout << "Seller " << name << " logged in" << endl; }
void Seller::logout() { cout << "Seller " << name << " logged out" << endl; }

void Seller::addProduct(const Product &pt) {
    if (p_count >= 50) throw Exception(101, "Product limit reached!");
    p[p_count++] = pt;
}

void Seller::deleteProduct(int pid) {
    for (int i = 0; i < p_count; i++) {
        if (p[i].product_id == pid) {
            for (int j = i; j < p_count - 1; j++) p[j] = p[j + 1];
            p_count--;
            return;
        }
    }
    throw Exception(102, "Product not found!");
}

void Seller::list_product() {
    for (int i = 0; i < p_count; i++) p[i].printdetails();
}
