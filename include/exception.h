#ifndef EXCEPTION_H
#define EXCEPTION_H

#include <iostream>
#include <string>
using namespace std;

class Exception {
public:
    int err_id;
    string errmsg;
    Exception() {}
    Exception(int e, string m) : err_id(e), errmsg(m) {}
    void show() { cout << err_id << ":" << errmsg << endl; }
};

#endif
