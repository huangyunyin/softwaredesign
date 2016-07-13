#ifndef _READ_PEOPLE_H
#define _READ_PEOPLE_H
#include <iostream>
#include <list>
#include <string>
#include <fstream>
#include "User.h"
using namespace std;

class ReadPeople {
public :
    ReadPeople(const char *fpath);
    ~ReadPeople(){}

    list<User> ReadFromFile();
    bool FindPeople(CString na, CString pass);
    User getPeople();
    bool isExist(CString name);
    void ChangePeople(User user);
    void deletePeople(CString name);
private:
    const char *file_path;
    User currentPeople;
};
#endif