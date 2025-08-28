#include "user.h"

User::User(string n, string e, string p, string a)
    : name(n), email(e), password(p), address(a) {}

void User::login() { cout << name << " logged in" << endl; }
void User::logout() { cout << name << " logged out" << endl; }

void User::update_profile(string n, string e, string a) {
    name = n;
    email = e;
    address = a;
    cout << "Profile updated: " << name << ", " << email << ", " << address << endl;
}

void User::reset_password(string new_password) {
    password = new_password;
    cout << "Password reset successfully" << endl;
}
