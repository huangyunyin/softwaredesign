#include <stdlib.h>
#include <fstream>
#include "stdafx.h"
#include "ReadPeople.h"
#include "WritePeople.h"

ReadPeople::ReadPeople(const char *fpath) {
    file_path = fpath;
}

list<User> ReadPeople::ReadFromFile() {
    ifstream input(file_path);
    list<User> user;
    string user_name;
    string user_password;
    string user_real;
    string user_id;
    string user_address;
    string user_phone;
    string user_mail;
    CString str1;
    CString str2;
    CString str3;
    CString str4;
    CString str5;
    CString str6;
    CString str7;
    int i;
    for (string s; getline(input, s);) {
        user_name = "";
        user_password = "";
        user_real = "";
        user_id = "";
        user_address = "";
        user_phone = "";
        user_mail = "";
        for (i = 0; s[i] != ','; i++) {
            user_name += s[i];
        }
        for (i++; s[i] != ','; i++) {
            user_password += s[i];
        }
        for (i++; s[i] != ','; i++) {
            user_real += s[i];
        }
        for (i++; s[i] != ','; i++) {
            user_id += s[i];
        }
        for (i++; s[i] != ','; i++) {
            user_address += s[i];
        }
        for (i++; s[i] != ','; i++) {
            user_phone += s[i];
        }
        for (i++; s[i] != '\0'; i++) {
            user_mail += s[i];
        }
        str1 = user_name.c_str();
        str2 = user_password.c_str();
        str3 = user_real.c_str();
        str4 = user_id.c_str();
        str5 = user_address.c_str();
        str6 = user_phone.c_str();
        str7 = user_mail.c_str();
        user.push_back(User(str1, str2, str3, str4, str5, str6, str7));
    }
    return user;
}

bool ReadPeople::FindPeople(CString name, CString password) {
    list<User> user_list = ReadFromFile();
    list<User>::iterator it;
    for (it = user_list.begin(); it != user_list.end(); it++) {
        if (name == it->getUserName() && password == it->getPassword()) {
            currentPeople = User(it->getUserName(), it->getPassword(), it->getRealName(), it->getIdNumber(), it->getAddress(), it->getPhone(), it->getMail());
            return true;
        }
    }
    if (it == user_list.end()) {
        return false;
    }
}

User ReadPeople::getPeople() {
    return currentPeople;
}

bool ReadPeople::isExist(CString name) {
    list<User> user_list = ReadFromFile();
    list<User>::iterator it;
    for (it = user_list.begin(); it != user_list.end(); it++) {
        if (name == it->getUserName()) {
            return true;
        }
    }
    if (it == user_list.end()) {
        return false;
    }
}

void ReadPeople::ChangePeople(User user) {
    list<User> user_list = ReadFromFile();
    list<User>::iterator it;
    for (it = user_list.begin(); it != user_list.end(); it++) {
        if (user.getUserName() == it->getUserName()) {
            user_list.erase(it);
            user_list.push_back(user);
            WritePeople write_people;
            write_people.WriteAllPeople(file_path, user_list);
            return;
        }
    }
    if (it == user_list.end()) {
        return;
    }
}

void ReadPeople::deletePeople(CString name) {
    list<User> user_list = ReadFromFile();
    list<User>::iterator it;
    for (it = user_list.begin(); it != user_list.end(); it++) {
        if (name == it->getUserName()) {
            user_list.erase(it);
            WritePeople write_people;
            write_people.WriteAllPeople(file_path, user_list);
            return;
        }
    }
}