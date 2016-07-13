#ifndef _WRITE_PEOPLE_H
#define _WRITE_PEOPLE_H

#include <iostream>
#include <list>
#include "User.h"

using namespace std;

class WritePeople {
public :
    WritePeople() {}
    ~WritePeople() {}

    void WritePeopleAfter(const char* fpath, User user);
    void WriteAllPeople(const char* fpath, list<User> user_list);
};
#endif