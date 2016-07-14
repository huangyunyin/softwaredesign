#pragma once
class Payment
{
public:
    Payment();
    ~Payment();
    Payment(CString n, CString ti, CString wa, CString ele, CString re, CString man, CString al, CString sta);
    CString getUserName() const;
    void setUserName(CString n);
    CString getTime() const;
    void setTime(CString ti);
    CString getWater() const;
    void setWater(CString wa);
    CString getElectric() const;
    void setElectric(CString ele);
    CString getRepair() const;
    void setRepair(CString re);
    CString getManage() const;
    void setManage(CString man);
    CString getAll() const;
    void setAll(CString al);
    CString getState() const;
    void setState(CString sta);

private:
    CString name;
    CString time;
    CString water;
    CString electric;
    CString repair;
    CString manage;
    CString all;
    CString state;
};

