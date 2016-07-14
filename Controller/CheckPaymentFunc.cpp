// CheckPaymentFunc.cpp : ʵ���ļ�
//

#include "stdafx.h"
#include "CheckPaymentFunc.h"
#include "afxdialogex.h"
#include "Payment.h"
#include "Login.h"
#include "User.h"
#include "ReadPayment.h"
extern User current_user;

// CheckPaymentFunc �Ի���

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


// CheckPaymentFunc ��Ϣ�������


BOOL CheckPaymentFunc::OnInitDialog() {
    CDialogEx::OnInitDialog();
    CRect rect;
    // ��ȡ��������б���ͼ�ؼ���λ�úʹ�С
    list_control.GetClientRect(&rect);
    // Ϊ�б���ͼ�ؼ����ȫ��ѡ�к�դ����
    list_control.SetExtendedStyle(list_control.GetExtendedStyle() | LVS_EX_FULLROWSELECT | LVS_EX_GRIDLINES);
    // Ϊ�б���ͼ�ؼ���Ӱ���
    list_control.InsertColumn(0, _T("ҵ������"), LVCFMT_CENTER, rect.Width() / 8, 0);
    list_control.InsertColumn(1, _T("�ɷ�����"), LVCFMT_CENTER, rect.Width() / 8, 1);
    list_control.InsertColumn(2, _T("ˮ��"), LVCFMT_CENTER, rect.Width() / 8, 2);
    list_control.InsertColumn(3, _T("���"), LVCFMT_CENTER, rect.Width() / 8, 3);
    list_control.InsertColumn(4, _T("ά�޷�"), LVCFMT_CENTER, rect.Width() / 8, 4);
    list_control.InsertColumn(5, _T("�����"), LVCFMT_CENTER, rect.Width() / 8, 5);
    list_control.InsertColumn(6, _T("�ɷ��ܶ�"), LVCFMT_CENTER, rect.Width() / 8, 6);
    list_control.InsertColumn(7, _T("�ɷ�״̬"), LVCFMT_CENTER, rect.Width() / 8, 7);
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

