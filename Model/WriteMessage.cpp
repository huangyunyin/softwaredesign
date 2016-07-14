#include "stdafx.h"
#include <stdlib.h>
#include <fstream>
#include "WriteMessage.h"

void WriteMessage::WriteMessageAfter(Message message) {
    ofstream output(file_path, ios::app);
    CString str;
    str.Format(_T("%d"), message.getNum());
    CStringA stra1(str);
    CStringA stra2(message.getUserName());
    CStringA stra3(message.getUserPhone());
    CStringA stra4(message.getTime());
    CStringA stra5(message.getTheme());
    CStringA stra6(message.getContents());
    CStringA stra7(message.getState());
    output << stra1 << '|' << stra2 << '|' << stra3 << '|' << stra4 << '|' << stra5 << '|' << stra6 << '|' << stra7 << endl;
}

void WriteMessage::WriteMessageAll(list<Message> message_list) {
    ofstream output(file_path);
    list<Message>::iterator it;
    for (it = message_list.begin(); it != message_list.end(); it++) {
        CString str;
        str.Format(_T("%d"), it->getNum());
        CStringA stra1(str);
        CStringA stra2(it->getUserName());
        CStringA stra3(it->getUserPhone());
        CStringA stra4(it->getTime());
        CStringA stra5(it->getTheme());
        CStringA stra6(it->getContents());
        CStringA stra7(it->getState());
        output << stra1 << '|' << stra2 << '|' << stra3 << '|' << stra4 << '|' << stra5 << '|' << stra6 << '|' << stra7 << endl;
    }
}