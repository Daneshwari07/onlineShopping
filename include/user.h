#ifndef USER_H
#define USER_H

#include <iostream>
#include <string>
using namespace std;

class User {
protected:
    string name;
    string email;
    string password;
    string address;

public:
    User() {}
    User(string n, string e, string p, string a);
    virtual void login();
    virtual void logout();
    void update_profile(string n, string e, string a);
    void reset_password(string new_password);
};

#endif
