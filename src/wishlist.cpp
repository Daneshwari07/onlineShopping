#include "wishlist.h"

void Wishlist::searchProduct(int pid) {
    for (int i = 0; i < p_count; i++) {
        if (p[i].product_id == pid) {
            cout << "Found in wishlist: ";
            p[i].printdetails();
            return;
        }
    }
    throw Exception(201, "Product not found in wishlist!");
}

void Wishlist::addWishlist(const Product &pt) {
    if (p_count >= 50) throw Exception(202, "Wishlist full!");
    p[p_count++] = pt;
}

void Wishlist::remove_wishlist(int pid) {
    for (int i = 0; i < p_count; i++) {
        if (p[i].product_id == pid) {
            for (int j = i; j < p_count - 1; j++) p[j] = p[j + 1];
            p_count--;
            return;
        }
    }
    throw Exception(203, "Product not found in wishlist!");
}

void Wishlist::display() {
    cout << "--- Wishlist ---" << endl;
    for (int i = 0; i < p_count; i++) p[i].printdetails();
}
