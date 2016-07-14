#ifndef _WRITEPAYMENT_H
#define _WRITEPAYMENT_H

#include <iostream>
#include <list>
#include "Payment.h"
using namespace std;

class WritePayment {
public :
    WritePayment(){}
    ~WritePayment(){}

    void WritePaymentAfter(const char* fpath, Payment payment);
};
#endif