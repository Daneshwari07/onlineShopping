#ifndef PAYMENT_H
#define PAYMENT_H

#include "order.h"
#include "exception.h"

class Payment {
protected:
    int payment_id;
    Order *order;
    string payment_method;
    string status;

public:
    Payment(int id, Order *o, string method, string stat)
        : payment_id(id), order(o), payment_method(method), status(stat) {}
    virtual void refund_payment(int payment_id) = 0;
    virtual void update_payment_status(int payment_id, string status) = 0;
    virtual void get_payment_details(int payment_id) = 0;
};

class OnlinePayment : public Payment {
private:
    string type;

public:
    OnlinePayment(int id, Order *o, string method, string stat, string t);
    void refund_payment(int payment_id) override;
    void update_payment_status(int payment_id, string status) override;
    void get_payment_details(int payment_id) override;
};

class OfflinePayment : public Payment {
public:
    OfflinePayment(int id, Order *o, string method, string stat);
    void refund_payment(int payment_id) override;
    void update_payment_status(int payment_id, string status) override;
    void get_payment_details(int payment_id) override;
};

#endif
