#include "stdafx.h"
#include <string>
#include "ReadPayment.h"

list<Payment> ReadPayment::ReadFromFile() {
    list<Payment> payment_list;
    ifstream input("Data\\Payment_list.txt");
    string name;
    string time;
    string water;
    string electric;
    string repair;
    string manage;
    string all;
    string state;
    CString str1;
    CString str2;
    CString str3;
    CString str4;
    CString str5;
    CString str6;
    CString str7;
    CString str8;
    int i;
    for (string s; getline(input, s);) {
        name = "";
        time = "";
        water = "";
        electric = "";
        repair = "";
        manage = "";
        all = "";
        state = "";
        for (i = 0; s[i] != '|'; i++) {
            name += s[i];
        }
        for (i++; s[i] != '|'; i++) {
            time += s[i];
        }
        for (i++; s[i] != '|'; i++) {
            water += s[i];
        }
        for (i++; s[i] != '|'; i++) {
            electric += s[i];
        }
        for (i++; s[i] != '|'; i++) {
            repair += s[i];
        }
        for (i++; s[i] != '|'; i++) {
            manage += s[i];
        }
        for (i++; s[i] != '|'; i++) {
            all += s[i];
        }
        for (i++; s[i] != '\0'; i++) {
            state += s[i];
        }
        str1 = name.c_str();
        str2 = time.c_str();
        str3 = water.c_str();
        str4 = electric.c_str();
        str5 = repair.c_str();
        str6 = manage.c_str();
        str7 = all.c_str();
        str8 = state.c_str();
        payment_list.push_back(Payment(str1, str2, str3, str4, str5, str6, str7, str8));
    }
    return payment_list;
}