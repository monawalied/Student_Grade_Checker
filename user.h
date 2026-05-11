#ifndef USER_H
#define USER_H
#include <string>
using namespace std;

enum Role { ADMIN, PROFESSOR, STUDENT_USER };

class User {
public:
    string username;
    string password;
    Role role;
    string id; // Used for students to find their own records
    User(string u, string p, Role r, string id = "")
        : username(u), password(p), role(r), id(id) {}
};

#endif

