#include "stdafx.h"
#include <stdlib.h>
#include <fstream>
#include "WritePayment.h"

void WritePayment::WritePaymentAfter(const char* fpath, Payment payment) {
    ofstream output(fpath, ios::app);
    CStringA stra1(payment.getUserName());
    CStringA stra2(payment.getTime());
    CStringA stra3(payment.getWater());
    CStringA stra4(payment.getElectric());
    CStringA stra5(payment.getRepair());
    CStringA stra6(payment.getManage());
    CStringA stra7(payment.getAll());
    CStringA stra8(payment.getState());
    output << stra1 << '|' << stra2 << '|' << stra3 << '|' << stra4 << '|' << stra5 << '|' << stra6 << '|' << stra7 << '|' << stra8 << endl;
}