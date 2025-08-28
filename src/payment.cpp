#include "payment.h"

OnlinePayment::OnlinePayment(int id, Order *o, string method, string stat, string t)
    : Payment(id, o, method, stat), type(t) {}

void OnlinePayment::refund_payment(int payment_id) {
    cout << "Refund initiated for Online Payment ID: " << payment_id << endl;
}

void OnlinePayment::update_payment_status(int payment_id, string stat) {
    status = stat;
    cout << "Online Payment ID " << payment_id << " status updated to " << status << endl;
}

void OnlinePayment::get_payment_details(int payment_id) {
    cout << "Online Payment ID: " << payment_id << " Status: " << status
         << " Type: " << type << endl;
}

OfflinePayment::OfflinePayment(int id, Order *o, string method, string stat)
    : Payment(id, o, method, stat) {}

void OfflinePayment::refund_payment(int payment_id) {
    cout << "Refund initiated for Offline Payment ID: " << payment_id << endl;
}

void OfflinePayment::update_payment_status(int payment_id, string stat) {
    status = stat;
    cout << "Offline Payment ID " << payment_id << " status updated to " << status << endl;
}

void OfflinePayment::get_payment_details(int payment_id) {
    cout << "Offline Payment ID: " << payment_id << " Status: " << status << endl;
}
