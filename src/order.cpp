#include "order.h"

Order::Order(int oid, string bname)
    : order_id(oid), buyer_name(bname), product_count(0), total_amount(0) {}

void Order::addProduct(const Product &product) {
    if (product_count >= MAX_CART) throw Exception(401, "Too many products in order!");
    products[product_count++] = product;
    total_amount += product.price;
}

void Order::printOrderDetails() const {
    cout << "--- Order Details ---" << endl;
    cout << "Order ID: " << order_id << " Buyer: " << buyer_name << endl;
    for (int i = 0; i < product_count; i++) products[i].printdetails();
    cout << "Total: " << total_amount << endl;
}
