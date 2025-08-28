#include "cart.h"

Cart::Cart(int c, int bid, double price)
    : cart_id(c), buyer_id(bid), tot(price), p_count(0) {}

void Cart::addCart(const Product &prod) {
    if (p_count >= MAX_CART) throw Exception(301, "Cart full!");
    p[p_count++] = prod;
    tot += prod.price;
}

void Cart::removefrom_cart(int pid) {
    for (int i = 0; i < p_count; i++) {
        if (p[i].product_id == pid) {
            tot -= p[i].price;
            for (int j = i; j < p_count - 1; j++) p[j] = p[j + 1];
            p_count--;
            return;
        }
    }
    throw Exception(302, "Product not found in cart!");
}

void Cart::applyDiscount() { tot *= 0.9; }

void Cart::displaydetails() {
    cout << "--- Cart Details ---" << endl;
    for (int i = 0; i < p_count; i++) p[i].printdetails();
    cout << "Total: " << tot << endl;
}

void Cart::clear_cart() {
    p_count = 0;
    tot = 0;
}
