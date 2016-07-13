#pragma once
#include<iostream>
#include<string>
using namespace std;
class User
{
public:
    User();
    ~User();
    User(CString userName, CString userPassword, CString realName,
        CString idNumber, CString userAddress, CString userPhone, CString userMail);
    CString getUserName() const;
    void setUserName(CString name);
    CString getPassword() const;
    void setPassword(CString password);
    CString getRealName() const;
    void setRealName(CString realName);
    CString getIdNumber() const;
    void setIdNumber(CString idNumber);
    CString getAddress() const;
    void setAddress(CString address);
    CString getPhone() const;
    void setPhone(CString phone);
    CString getMail() const;
    void setMail(CString mail);
private:
    CString user_name;
    CString user_password;
    CString proprietor_name;
    CString user_id;
    CString user_address;
    CString user_phone;
    CString user_mail;
};

