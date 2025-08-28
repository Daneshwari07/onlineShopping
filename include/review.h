#ifndef REVIEW_H
#define REVIEW_H

#include "product.h"
#include "exception.h"

class Review {
private:
    int review_id;
    Product *p;
    int buyer_id;
    int rating;
    string comment;

public:
    Review(int rid, Product *prod, int bid, int rt, string cm);
    void submit_review();
    void update_review(int rid);
    void delete_review(int rid);
    void get_review_details(int rid);
};

#endif
