#include "stdafx.h"
#include <stdlib.h>
#include <fstream>
#include "WritePeople.h"
#include "User.h"


void WritePeople::WritePeopleAfter(const char* fpath, User user) {
    ofstream output(fpath, ios::app);//在文件尾写入，而非覆盖整个文件内容
    CStringA stra1(user.getUserName());
    CStringA stra2(user.getPassword());
    CStringA stra3(user.getRealName());
    CStringA stra4(user.getIdNumber());
    CStringA stra5(user.getAddress());
    CStringA stra6(user.getPhone());
    CStringA stra7(user.getMail());
    output << stra1 << ',' << stra2 << ',' << stra3 << ',' << stra4 << ',' << stra5 << ',' << stra6 << ',' << stra7 << endl;
}

void WritePeople::WriteAllPeople(const char* fpath, list<User> user_list) {
    ofstream output(fpath);
    list<User>::iterator it;
    for (it = user_list.begin(); it != user_list.end(); it++) {
        CStringA stra1(it->getUserName());
        CStringA stra2(it->getPassword());
        CStringA stra3(it->getRealName());
        CStringA stra4(it->getIdNumber());
        CStringA stra5(it->getAddress());
        CStringA stra6(it->getPhone());
        CStringA stra7(it->getMail());
        output << stra1 << ',' << stra2 << ',' << stra3 << ',' << stra4 << ',' << stra5 << ',' << stra6 << ',' << stra7 << endl;
    }
}