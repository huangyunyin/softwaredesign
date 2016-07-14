#include "stdafx.h"
#include <string>
#include "ReadMessage.h"

list<Message> ReadMessage::ReadFromFile() {
    list<Message> message_list;
    ifstream input(file_path);
    string num;
    string name;
    string phone;
    string time;
    string theme;
    string contents;
    string state;
    int str1;
    CString str2;
    CString str3;
    CString str4;
    CString str5;
    CString str6;
    CString str7;
    int i;
    for (string s; getline(input, s);) {
        num = "";
        name = "";
        phone = "";
        time = "";
        theme = "";
        contents = "";
        state = "";
        for (i = 0; s[i] != '|'; i++) {
            num += s[i];
        }
        for (i++; s[i] != '|'; i++) {
            name += s[i];
        }
        for (i++; s[i] != '|'; i++) {
            phone += s[i];
        }
        for (i++; s[i] != '|'; i++) {
            time += s[i];
        }
        for (i++; s[i] != '|'; i++) {
            theme += s[i];
        }
        for (i++; s[i] != '|'; i++) {
            contents += s[i];
        }
        for (i++; s[i] != '\0'; i++) {
            state += s[i];
        }
        str1 = atoi(num.c_str());
        str2 = name.c_str();
        str3 = phone.c_str();
        str4 = time.c_str();
        str5 = theme.c_str();
        str6 = contents.c_str();
        str7 = state.c_str();
        message_list.push_back(Message(str1, str2, str3, str4, str5, str6, str7));
    }
    return message_list;
}