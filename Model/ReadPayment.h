#ifndef _READ_PAYMENT_H
#define _READ_PAYMENT_H
#include <iostream>
#include <list>
#include <fstream>
#include "Payment.h"
using namespace std;

class ReadPayment {
public :
    ReadPayment() {}
    ~ReadPayment() {}

    list<Payment> ReadFromFile();
};
#endif