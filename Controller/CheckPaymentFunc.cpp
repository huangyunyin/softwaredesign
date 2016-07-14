// CheckPaymentFunc.cpp : 实现文件
//

#include "stdafx.h"
#include "CheckPaymentFunc.h"
#include "afxdialogex.h"
#include "Payment.h"
#include "Login.h"
#include "User.h"
#include "ReadPayment.h"
extern User current_user;

// CheckPaymentFunc 对话框

IMPLEMENT_DYNAMIC(CheckPaymentFunc, CDialogEx)

CheckPaymentFunc::CheckPaymentFunc(CWnd* pParent /*=NULL*/)
	: CDialogEx(CheckPaymentFunc::IDD, pParent)
{

}

CheckPaymentFunc::~CheckPaymentFunc()
{
}

void CheckPaymentFunc::DoDataExchange(CDataExchange* pDX)
{
    CDialogEx::DoDataExchange(pDX);
    DDX_Control(pDX, IDC_LIST1, list_control);
}


BEGIN_MESSAGE_MAP(CheckPaymentFunc, CDialogEx)
END_MESSAGE_MAP()


// CheckPaymentFunc 消息处理程序


BOOL CheckPaymentFunc::OnInitDialog() {
    CDialogEx::OnInitDialog();
    CRect rect;
    // 获取编程语言列表视图控件的位置和大小
    list_control.GetClientRect(&rect);
    // 为列表视图控件添加全行选中和栅格风格
    list_control.SetExtendedStyle(list_control.GetExtendedStyle() | LVS_EX_FULLROWSELECT | LVS_EX_GRIDLINES);
    // 为列表视图控件添加八列
    list_control.InsertColumn(0, _T("业主姓名"), LVCFMT_CENTER, rect.Width() / 8, 0);
    list_control.InsertColumn(1, _T("缴费日期"), LVCFMT_CENTER, rect.Width() / 8, 1);
    list_control.InsertColumn(2, _T("水费"), LVCFMT_CENTER, rect.Width() / 8, 2);
    list_control.InsertColumn(3, _T("电费"), LVCFMT_CENTER, rect.Width() / 8, 3);
    list_control.InsertColumn(4, _T("维修费"), LVCFMT_CENTER, rect.Width() / 8, 4);
    list_control.InsertColumn(5, _T("管理费"), LVCFMT_CENTER, rect.Width() / 8, 5);
    list_control.InsertColumn(6, _T("缴费总额"), LVCFMT_CENTER, rect.Width() / 8, 6);
    list_control.InsertColumn(7, _T("缴费状态"), LVCFMT_CENTER, rect.Width() / 8, 7);
    ReadPayment read_payment;
    list<Payment> payment_list = read_payment.ReadFromFile();
    std::list<Payment>::iterator it;
    int i = 0;
    for (it = payment_list.begin(); it != payment_list.end(); it++) {
        if (it->getUserName() == current_user.getRealName()) {
            list_control.InsertItem(i, it->getUserName());
            list_control.SetItemText(i, 1, it->getTime());
            list_control.SetItemText(i, 2, it->getWater());
            list_control.SetItemText(i, 3, it->getElectric());
            list_control.SetItemText(i, 4, it->getRepair());
            list_control.SetItemText(i, 5, it->getManage());
            list_control.SetItemText(i, 6, it->getAll());
            list_control.SetItemText(i, 7, it->getState());
            i++;
        }
    }
    return true;
}

