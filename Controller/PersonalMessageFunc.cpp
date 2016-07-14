// PersonalMessageFunc.cpp : 实现文件
//

#include "stdafx.h"
#include "PersonalMessageFunc.h"
#include "afxdialogex.h"
#include "Login.h"
#include "User.h"
#include <fstream>
#include "ReadPeople.h"
// PersonalMessageFunc 对话框

extern User current_user;

IMPLEMENT_DYNAMIC(PersonalMessageFunc, CDialogEx)

PersonalMessageFunc::PersonalMessageFunc(CWnd* pParent /*=NULL*/)
	: CDialogEx(PersonalMessageFunc::IDD, pParent)
{
}

PersonalMessageFunc::~PersonalMessageFunc()
{
}

void PersonalMessageFunc::DoDataExchange(CDataExchange* pDX)
{
	CDialogEx::DoDataExchange(pDX);
}


BEGIN_MESSAGE_MAP(PersonalMessageFunc, CDialogEx)
    ON_BN_CLICKED(IDC_BUTTON1, &PersonalMessageFunc::OnBnClickedButton1)
END_MESSAGE_MAP()


// PersonalMessageFunc 消息处理程序
BOOL PersonalMessageFunc::OnInitDialog() {
    CDialogEx::OnInitDialog();
    GetDlgItem(IDC_EDIT1)->SetWindowText(current_user.getUserName());
    GetDlgItem(IDC_EDIT2)->SetWindowText(current_user.getRealName());
    GetDlgItem(IDC_EDIT3)->SetWindowText(current_user.getAddress());
    GetDlgItem(IDC_EDIT4)->SetWindowText(current_user.getIdNumber());
    GetDlgItem(IDC_EDIT5)->SetWindowText(current_user.getPhone());
    GetDlgItem(IDC_EDIT6)->SetWindowText(current_user.getMail());
    return true;
}


//提交更改按钮
void PersonalMessageFunc::OnBnClickedButton1()
{
    // TODO:  在此添加控件通知处理程序代码
    CString idNumber;
    CString phoneNunber;
    CString mailNumber;
    GetDlgItem(IDC_EDIT4)->GetWindowText(idNumber);
    GetDlgItem(IDC_EDIT5)->GetWindowText(phoneNunber);
    GetDlgItem(IDC_EDIT6)->GetWindowText(mailNumber);
    current_user.setIdNumber(idNumber);
    current_user.setPhone(phoneNunber);
    current_user.setMail(mailNumber);

    ReadPeople read_people("Data\\User_list.txt");
    read_people.ChangePeople(current_user);

    AfxMessageBox(_T("更改成功！"));
}
