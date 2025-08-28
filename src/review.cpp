#include "review.h"

Review::Review(int rid, Product *prod, int bid, int rt, string cm)
    : review_id(rid), p(prod), buyer_id(bid), rating(rt), comment(cm) {}

void Review::submit_review() {
    cout << "Review submitted: " << rating << " stars - " << comment << endl;
}

void Review::update_review(int rid) {
    if (review_id == rid) {
        cout << "Review updated for ID: " << rid << endl;
    } else {
        throw Exception(601, "Review ID not found!");
    }
}

void Review::delete_review(int rid) {
    if (review_id == rid) {
        cout << "Review deleted for ID: " << rid << endl;
    } else {
        throw Exception(602, "Review ID not found!");
    }
}

void Review::get_review_details(int rid) {
    if (review_id == rid) {
        cout << "Review ID: " << review_id << " Rating: " << rating
             << " Comment: " << comment << endl;
    } else {
        throw Exception(603, "Review ID not found!");
    }
}
