#include <iostream>
using namespace std;

class User {
public:
  string name;
  string pass;
  bool operator==(const User &us) { return name == us.name && pass == us.pass; }
};

class DataBase {
public:
  User *users;
  int count;
  bool SignIn(const User &us) {
    for (int i = 0; i < count; i++) {
      if (users[i] == us) {
        return true;
      }
    }
    return false;
  }
  bool SignUp(const User &us) {
    for (int i = 0; i < count; i++) {
      if (users[i].name == us.name) {
        return false;
      }
    }
    User *temp = new User[count + 1];
    for (int i = 0; i < count; i++) {
      temp[i].name = users[i].name;
      temp[i].pass = users[i].pass;
    }
    return true;
  }
};