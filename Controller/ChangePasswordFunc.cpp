// ChangePasswordFunc.cpp : 实现文件
//

#include "stdafx.h"
#include "ChangePasswordFunc.h"
#include "afxdialogex.h"
#include "PersonalMessageFunc.h"
#include "Login.h"
#include "User.h"
#include "ReadPeople.h"

extern CDialogEx *v;
extern User current_user;
// ChangePasswordFunc 对话框

IMPLEMENT_DYNAMIC(ChangePasswordFunc, CDialogEx)

ChangePasswordFunc::ChangePasswordFunc(CWnd* pParent /*=NULL*/)
	: CDialogEx(ChangePasswordFunc::IDD, pParent)
{

}

ChangePasswordFunc::~ChangePasswordFunc()
{
}

void ChangePasswordFunc::DoDataExchange(CDataExchange* pDX)
{
	CDialogEx::DoDataExchange(pDX);
}


BEGIN_MESSAGE_MAP(ChangePasswordFunc, CDialogEx)
    ON_BN_CLICKED(IDC_BUTTON1, &ChangePasswordFunc::OnBnClickedButton1)
END_MESSAGE_MAP()


// ChangePasswordFunc 消息处理程序
BOOL ChangePasswordFunc::OnInitDialog() {
    CDialogEx::OnInitDialog();
    GetDlgItem(IDC_EDIT1)->SetWindowText(current_user.getUserName());
    return true;
}


//提交修改按钮的处理函数
void ChangePasswordFunc::OnBnClickedButton1()
{
    // TODO:  在此添加控件通知处理程序代码
    CString current_password;
    CString confirm_password;
    GetDlgItem(IDC_EDIT2)->GetWindowText(current_password);
    GetDlgItem(IDC_EDIT3)->GetWindowText(confirm_password);
    if (current_password.GetLength() < 8) {
        AfxMessageBox(_T("密码长度应不小于8！"));
        return;
    }
    if (current_password != confirm_password) {
        AfxMessageBox(_T("两次密码不相同！"));
        return;
    }
    int i = 0;
    while (i < current_password.GetLength()) {
        if (isRightType(current_password[i])) {
            i++;
        }
        else {
            AfxMessageBox(_T("密码格式不正确！"));
            return;
        }
    }
    current_user.setPassword(current_password);

    ReadPeople read_people("Data\\User_list.txt");
    read_people.ChangePeople(current_user);

    delete v;
    v = new ChangePasswordFunc;
    v->Create(IDD_FORMVIEW1, GetActiveWindow());
    v->ShowWindow(SW_SHOWNORMAL);
    v->MoveWindow(135, 90, 848, 451);
    AfxMessageBox(_T("更改成功！"));
}

//密码格式是否正确
bool ChangePasswordFunc::isRightType(char ch) {
    if ((ch > 64 && ch < 91) || (ch > 96 && ch < 123) || (ch > 47 && ch < 58)) {
        return true;
    }
    return false;
}