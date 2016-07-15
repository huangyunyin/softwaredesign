// ManagerPaymentFunc.cpp : 实现文件
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


// ManagerPaymentFunc 对话框

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


// ManagerPaymentFunc 消息处理程序


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


//添加按钮
void ManagerPaymentFunc::OnBnClickedButton1()
{
    // TODO:  在此添加控件通知处理程序代码
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


//提交按钮处理函数
void ManagerPaymentFunc::OnBnClickedButton2()
{
    // TODO:  在此添加控件通知处理程序代码
    CString water;
    CString electric;
    CString repair;
    CString manage;
    GetDlgItem(IDC_EDIT8)->GetWindowText(water);
    GetDlgItem(IDC_EDIT9)->GetWindowText(electric);
    GetDlgItem(IDC_EDIT10)->GetWindowText(repair);
    GetDlgItem(IDC_EDIT11)->GetWindowText(manage);
    if (currentSelect.getRealName().GetLength() == 0) {
        ::MessageBox(NULL, _T("请添加用户！"), _T("缴费管理"), MB_OK);
        return;
    }
    if (water.GetLength() == 0) {
        ::MessageBox(NULL, _T("水费不能为空！"), _T("缴费管理"), MB_OK);
        return;
    }
    if (electric.GetLength() == 0) {
        ::MessageBox(NULL, _T("电费不能为空！"), _T("缴费管理"), MB_OK);
        return;
    }
    if (repair.GetLength() == 0) {
        ::MessageBox(NULL, _T("维修费不能为空！"), _T("缴费管理"), MB_OK);
        return;
    }
    if (manage.GetLength() == 0) {
        ::MessageBox(NULL, _T("管理费不能为空！"), _T("缴费管理"), MB_OK);
        return;
    }
    int sum = _ttoi(water) + _ttoi(electric) + _ttoi(repair) + _ttoi(manage);
    CString all;
    all.Format(_T("%d"), sum);
    CTime tm;
    m_date.GetTime(tm);
    CString time = tm.Format("%Y年%m月");
    CString warning = time + _T("缴费总额：") + all;
    INT_PTR nRes;
    nRes = MessageBox(warning, _T("缴费管理"), MB_OKCANCEL | MB_ICONQUESTION);
    if (IDOK == nRes) {
        CString name = currentSelect.getRealName();
        CString state = _T("未缴费");
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