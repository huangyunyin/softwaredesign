// ManagerPaymentFunc.cpp : ʵ���ļ�
//

#include "stdafx.h"
#include "ManagerPaymentFunc.h"
#include "afxdialogex.h"
#include "User.h"
#include "Login.h"
#include "Payment.h"
#include <fstream>
#include "ReadPeople.h"
#include "WritePayment.h"
extern CDialogEx *v;


// ManagerPaymentFunc �Ի���

IMPLEMENT_DYNAMIC(ManagerPaymentFunc, CDialogEx)

ManagerPaymentFunc::ManagerPaymentFunc(CWnd* pParent /*=NULL*/)
	: CDialogEx(ManagerPaymentFunc::IDD, pParent)
{
    currentSelect = User();
}

ManagerPaymentFunc::~ManagerPaymentFunc()
{
}

void ManagerPaymentFunc::DoDataExchange(CDataExchange* pDX)
{
    CDialogEx::DoDataExchange(pDX);
    DDX_Control(pDX, IDC_COMBO1, select_user);
    DDX_Control(pDX, IDC_DATETIMEPICKER1, m_date);
}


BEGIN_MESSAGE_MAP(ManagerPaymentFunc, CDialogEx)
    ON_BN_CLICKED(IDC_BUTTON1, &ManagerPaymentFunc::OnBnClickedButton1)
    ON_BN_CLICKED(IDC_BUTTON2, &ManagerPaymentFunc::OnBnClickedButton2)
END_MESSAGE_MAP()


// ManagerPaymentFunc ��Ϣ�������


BOOL ManagerPaymentFunc::OnInitDialog() {
    CDialogEx::OnInitDialog();
    ReadPeople read_people("Data\\User_list.txt");
    list<User> user_list = read_people.ReadFromFile();
    std::list<User>::iterator it;
    for (it = user_list.begin(); it != user_list.end(); it++) {
        select_user.AddString(it->getRealName());
    }
    return true;
}


//��Ӱ�ť
void ManagerPaymentFunc::OnBnClickedButton1()
{
    // TODO:  �ڴ���ӿؼ�֪ͨ����������
    CString str;
    select_user.GetLBText(select_user.GetCurSel(), str);
    ReadPeople read_people("Data\\User_list.txt");
    list<User> user_list = read_people.ReadFromFile();
    std::list<User>::iterator it;
    for (it = user_list.begin(); it != user_list.end(); it++) {
        if (it->getRealName() == str) {
            currentSelect = *it;
            break;
        }
    }
    GetDlgItem(IDC_EDIT1)->SetWindowText(currentSelect.getUserName());
    GetDlgItem(IDC_EDIT2)->SetWindowText(currentSelect.getRealName());
    GetDlgItem(IDC_EDIT3)->SetWindowText(currentSelect.getAddress());
    GetDlgItem(IDC_EDIT4)->SetWindowText(currentSelect.getIdNumber());
    GetDlgItem(IDC_EDIT5)->SetWindowText(currentSelect.getPhone());
    GetDlgItem(IDC_EDIT6)->SetWindowText(currentSelect.getMail());
}


//�ύ��ť������
void ManagerPaymentFunc::OnBnClickedButton2()
{
    // TODO:  �ڴ���ӿؼ�֪ͨ����������
    CString water;
    CString electric;
    CString repair;
    CString manage;
    GetDlgItem(IDC_EDIT8)->GetWindowText(water);
    GetDlgItem(IDC_EDIT9)->GetWindowText(electric);
    GetDlgItem(IDC_EDIT10)->GetWindowText(repair);
    GetDlgItem(IDC_EDIT11)->GetWindowText(manage);
    if (currentSelect.getRealName().GetLength() == 0) {
        ::MessageBox(NULL, _T("������û���"), _T("�ɷѹ���"), MB_OK);
        return;
    }
    if (water.GetLength() == 0) {
        ::MessageBox(NULL, _T("ˮ�Ѳ���Ϊ�գ�"), _T("�ɷѹ���"), MB_OK);
        return;
    }
    if (electric.GetLength() == 0) {
        ::MessageBox(NULL, _T("��Ѳ���Ϊ�գ�"), _T("�ɷѹ���"), MB_OK);
        return;
    }
    if (repair.GetLength() == 0) {
        ::MessageBox(NULL, _T("ά�޷Ѳ���Ϊ�գ�"), _T("�ɷѹ���"), MB_OK);
        return;
    }
    if (manage.GetLength() == 0) {
        ::MessageBox(NULL, _T("����Ѳ���Ϊ�գ�"), _T("�ɷѹ���"), MB_OK);
        return;
    }
    int sum = _ttoi(water) + _ttoi(electric) + _ttoi(repair) + _ttoi(manage);
    CString all;
    all.Format(_T("%d"), sum);
    CTime tm;
    m_date.GetTime(tm);
    CString time = tm.Format("%Y��%m��");
    CString warning = time + _T("�ɷ��ܶ") + all;
    INT_PTR nRes;
    nRes = MessageBox(warning, _T("�ɷѹ���"), MB_OKCANCEL | MB_ICONQUESTION);
    if (IDOK == nRes) {
        CString name = currentSelect.getRealName();
        CString state = _T("δ�ɷ�");
        Payment payment = Payment(name, time, water, electric, repair, manage, all, state);
        WritePayment write_payment;
        write_payment.WritePaymentAfter("Data\\Payment_list.txt", payment);

        delete v;
        v = new ManagerPaymentFunc;
        v->Create(IDD_FORMVIEW15, GetActiveWindow());
        v->ShowWindow(SW_SHOWNORMAL);
        v->MoveWindow(135, 90, 848, 451);
    }
    else {
        return;
    }
}