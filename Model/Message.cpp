#include "stdafx.h"
#include "Message.h"


Message::Message()
{
}


Message::~Message()
{
}

Message::Message(int n, CString name, CString phone, CString ti, CString the, CString con, CString sta) {
    num = n;
    user_name = name;
    user_phone = phone;
    time = ti;
    theme = the;
    contents = con;
    state = sta;
}

int Message::getNum() const {
    return num;
}
void Message::setNum(int n) {
    num = n;
}
CString Message::getUserName() const {
    return user_name;
}
void Message::setUserName(CString name) {
    user_name = name;
}
CString Message::getUserPhone() const {
    return user_phone;
}
void Message::setUserPhone(CString phone) {
    user_phone = phone;
}
CString Message::getTime() const {
    return time;
}
void Message::setTime(CString ti) {
    time = ti;
}
CString Message::getTheme() const {
    return theme;
}
void Message::setTheme(CString the) {
    theme = the;
}
CString Message::getContents() const {
    return contents;
}
void Message::setContents(CString con) {
    contents = con;
}
CString Message::getState() const {
    return state;
}
void Message::setState(CString sta) {
    state = sta;
}
bool Message::operator < (const Message &other) {
    return num < other.getNum();
}
