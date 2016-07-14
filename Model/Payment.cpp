#include "stdafx.h"
#include "Payment.h"


Payment::Payment()
{
}


Payment::~Payment()
{
}

Payment::Payment(CString n, CString ti, CString wa, CString ele, CString re, CString man, CString al, CString sta) {
    name = n;
    time = ti;
    water = wa;
    electric = ele;
    repair = re;
    manage = man;
    all = al;
    state = sta;
}
CString Payment::getUserName() const {
    return name;
}
void Payment::setUserName(CString n) {
    name = n;
}
CString Payment::getTime() const {
    return time;
}
void Payment::setTime(CString ti) {
    time = ti;
}
CString Payment::getWater() const {
    return water;
}
void Payment::setWater(CString wa) {
    water = wa;
}
CString Payment::getElectric() const {
    return electric;
}
void Payment::setElectric(CString ele) {
    electric = ele;
}
CString Payment::getRepair() const {
    return repair;
}
void Payment::setRepair(CString re) {
    repair = re;
}
CString Payment::getManage() const {
    return manage;
}
void Payment::setManage(CString man) {
    manage = man;
}
CString Payment::getAll() const {
    return all;
}
void Payment::setAll(CString al) {
    all = al;
}
CString Payment::getState() const {
    return state;
}
void Payment::setState(CString sta) {
    state = sta;
}