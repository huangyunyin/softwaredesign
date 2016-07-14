#pragma once
class Message
{
public:
    Message();
    ~Message();
    Message(int n, CString name, CString phone, CString ti, CString the, CString con, CString sta);
    int getNum() const;
    void setNum(int n);
    CString getUserName() const;
    void setUserName(CString name);
    CString getUserPhone() const;
    void setUserPhone(CString phone);
    CString getTime() const;
    void setTime(CString ti);
    CString getTheme() const;
    void setTheme(CString the);
    CString getContents() const;
    void setContents(CString con);
    CString getState() const;
    void setState(CString sta);
    bool operator < (const Message &other);
private:
    int num;
    CString user_name;
    CString user_phone;
    CString time;
    CString theme;
    CString contents;
    CString state;
};

