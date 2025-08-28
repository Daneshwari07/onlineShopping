// #include <iostream>
// #include "Seller.h"
// #include "buyer.h"
// #include "wishlist.h"
// #include "cart.h"
// #include "order.h"
// #include "payment.h"
// #include "review.h"

// using namespace std;

// int main() {
//     cout << "=== Online Shopping System ===" << endl;

//     Product p1(1, "Laptop", 55000, 5);
//     Seller s("Ravi", "ravi@email.com", "pass123", "Delhi", 101, "RaviStore", 4.5);
//     s.addProduct(p1);
//     s.list_Product();

//     Buyer b("Anu", "anu@email.com", "pass123", "Mumbai", 201);
//     b.add_to_cart(p1);
//     b.place_order();
//     b.invoice();

//     Review r1(1, &p1, 201, 5, "Great Product!");
//     r1.submit_review();

//     return 0;
// }

#include <iostream>
#include <string>
#include "buyer.h"
#include "cart.h"
#include "order.h"
#include "product.h"
#include "seller.h"
#include "wishlist.h"
#include "payment.h"
#include "review.h"
#include "user.h"

using namespace std;

int main()
{
    Seller *se = nullptr;
    Buyer *b = nullptr;
    bool exit = false;

    // Sample Products
    Product sampleProducts[] = {
        Product(1, "Laptop", 50000, 10),
        Product(2, "Phone", 20000, 15),
        Product(3, "Headphones", 2000, 20)};
    int sampleCount = sizeof(sampleProducts) / sizeof(sampleProducts[0]);

    cout << "Welcome to Online Shopping!" << endl;
    cout << "\nSample Products Available:" << endl;
    for (int i = 0; i < sampleCount; i++)
    {
        cout << sampleProducts[i].product_id << ". "
             << sampleProducts[i].name << " - Rs "
             << sampleProducts[i].price << " | Stock: "
             << sampleProducts[i].stock_quantity << endl;
    }

    while (!exit)
    {
        cout << "\nMain Menu:" << endl;
        cout << "1. Add Seller" << endl;
        cout << "2. Add Product to Seller" << endl;
        cout << "3. List Seller Products" << endl;
        cout << "4. Add Buyer" << endl;
        cout << "5. Add Product to Cart" << endl;
        cout << "6. Remove Product from Cart" << endl;
        cout << "7. Place Order" << endl;
        cout << "8. View Order Status" << endl;
        cout << "9. Invoice" << endl;
        cout << "10. Add Product to Wishlist" << endl;
        cout << "11. Display Wishlist" << endl;
        cout << "12. Exit" << endl;

        int choice;
        cin >> choice;

        switch (choice)
        {
        case 1:
        {
            string n, e, p, a, st;
            int sid;
            float r;
            cout << "Enter Seller details (name email password address Seller_id store rating): ";
            cin >> n >> e >> p >> a >> sid >> st >> r;
            if (se)
                delete se;
            se = new Seller(n, e, p, a, sid, st, r);
            break;
        }

        case 2:
        {
            if (!se)
            {
                cout << "Add a Seller first!" << endl;
                break;
            }
            int pid, quantity;
            string pname;
            double price;
            cout << "Enter Product details (id name price quantity): ";
            cin >> pid >> pname >> price >> quantity;
            se->addProduct(Product(pid, pname, price, quantity));
            break;
        }

        case 3:
        {
            if (!se)
            {
                cout << "Add a Seller first!" << endl;
                break;
            }
            se->list_product();
            break;
        }

        case 4:
        {
            string n, e, p, a;
            int bid;
            cout << "Enter Buyer details (name email password address buyer_id): ";
            cin >> n >> e >> p >> a >> bid;
            if (b)
                delete b;
            b = new Buyer(n, e, p, a, bid);
            break;
        }

        case 5:
        {
            if (!b)
            {
                cout << "Add a buyer first!" << endl;
                break;
            }
            int pid, quantity;
            string pname;
            double price;
            cout << "Enter Product details (id name price quantity): ";
            cin >> pid >> pname >> price >> quantity;
            Product p(pid, pname, price, quantity);
            b->add_to_cart(p);
            break;
        }

        case 6:
        {
            if (!b)
            {
                cout << "Add a buyer first!" << endl;
                break;
            }
            int pid;
            cout << "Enter Product ID to remove from cart: ";
            cin >> pid;
            b->remove_from_cart(pid);
            break;
        }

        case 7:
        {
            if (!b)
            {
                cout << "Add a buyer first!" << endl;
                break;
            }

            // Place the order
            b->place_order();

            // Ask for payment method
            int paymentChoice;
            cout << "\nChoose Payment Method:" << endl;
            cout << "1. Online Payment" << endl;
            cout << "2. Offline Payment (Cash on Delivery)" << endl;
            cin >> paymentChoice;

            if (paymentChoice == 1)
            {
                cout << "You selected Online Payment." << endl;
                cout << "Processing Online Payment..." << endl;
            }
            else if (paymentChoice == 2)
            {
                cout << "You selected Offline Payment (Cash on Delivery)." << endl;
            }
            else
            {
                cout << "Invalid choice. Defaulting to Offline Payment." << endl;
            }

            cout << "\n✅ Your order has been successfully placed!" << endl;
            break;
        }

        case 8:
        {
            if (!b)
            {
                cout << "Add a buyer first!" << endl;
                break;
            }
            int oid;
            cout << "Enter order ID to view status: ";
            cin >> oid;
            b->view_order_status(oid);
            break;
        }

        case 9:
        {
            if (!b)
            {
                cout << "Add a buyer first!" << endl;
                break;
            }
            b->invoice();
            break;
        }

        case 10:
        {
            if (!b)
            {
                cout << "Add a buyer first!" << endl;
                break;
            }
            int pid, quantity;
            string pname;
            double price;
            cout << "Enter Product details to add to wishlist: ";
            cin >> pid >> pname >> price >> quantity;
            Product p(pid, pname, price, quantity);
            b->list_Wishlist(p);
            break;
        }

        case 11:
        {
            if (!b)
            {
                cout << "Add a buyer first!" << endl;
                break;
            }
            b->w.display();
            break;
        }

        case 12:
            exit = true;
            break;

        default:
            cout << "Invalid choice!" << endl;
        }
    }

    // Cleanup
    if (se)
        delete se;
    if (b)
        delete b;

    return 0;
}
