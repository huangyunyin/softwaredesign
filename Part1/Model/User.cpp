#include "stdafx.h"
#include "User.h"


User::User()
{
}


User::~User()
{
}

User::User(CString userName, CString userPassword, CString realName,
    CString idNumber, CString userAddress, CString userPhone, CString userMail) {
    user_name = userName;
    user_password = userPassword;
    proprietor_name = realName;
    user_id = idNumber;
    user_address = userAddress;
    user_phone = userPhone;
    user_mail = userMail;
}

CString User::getUserName() const {
    return user_name;
}
void User::setUserName(CString name) {
    user_name = name;
}
CString User::getPassword() const {
    return user_password;
}
void User::setPassword(CString password) {
    user_password = password;
}
CString User::getRealName() const {
    return proprietor_name;
}
void User::setRealName(CString realName) {
    proprietor_name = realName;
}
CString User::getIdNumber() const {
    return user_id;
}
void User::setIdNumber(CString idNumber) {
    user_id = idNumber;
}
CString User::getAddress() const {
    return user_address;
}
void User::setAddress(CString address) {
    user_address = address;
}
CString User::getPhone() const {
    return user_phone;
}
void User::setPhone(CString phone) {
    user_phone = phone;
}
CString User::getMail() const {
    return user_mail;
}
void User::setMail(CString mail) {
    user_mail = mail;
}
